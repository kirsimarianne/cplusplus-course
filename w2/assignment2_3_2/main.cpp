#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

const float OUTLIER = 5.0;

struct SensorData
{
    int timestamp;
    std::string id;
    float value;
};

/* E1: Function simulates data ingestion.
 * Stores timestamp, sensor ID and sensor value variables to SensorData struct
 * and stores sturcts to data_list getting as parameter
 */
void data_ingestion(std::vector<SensorData>& data_list, long int timestamp, std::string id, float value)
{
    SensorData sensor_data;
    sensor_data.timestamp = timestamp;
    sensor_data.id = id;
    sensor_data.value = value;

    data_list.push_back(sensor_data);
}

/* E2: Function takes data_list and id as a paranmters
 * and returns filtered_data
*/
std::vector<SensorData> filter_readings(const std::vector<SensorData>& data_vect, std::string target_id)
{
    std::vector<SensorData> filtered_data;

    for(auto elem : data_vect)
    {
        if(elem.id == target_id)
        {
            data_ingestion(filtered_data, elem.timestamp, elem.id, elem.value);
        }
    }
    return filtered_data; 
}

/* E3: Function sorts filtered_data in ascending order
*/
void sort_data(std::vector<SensorData>& filtered_data)
{
    //comparing left and right element and return true if left element's timestamp smaller
    //than right element's timestamp. Otherwise return true.
    std::sort(filtered_data.begin(), filtered_data.end(),
                 [](auto &left, auto &right)
                 { 
                        return left.timestamp < right.timestamp; 
                 });         
}

/* E4: Function detects outliers in sensor data
 * and returns vector of outliers
 */

std::vector<SensorData> detect_outliers(std::vector<SensorData>& vect)
{
    std::vector<SensorData> outliers {};
    float sum{};
    for(auto elem : vect)
    {
        sum += elem.value;
    }
    float mean = sum/static_cast<float>(vect.size());
    for(auto elem : vect)
    {
        if(elem.value > mean+OUTLIER || elem.value < mean-OUTLIER)
        {
            outliers.push_back(elem);
        }
    }

    return outliers;
}

/* E5: Find sensor that has the highest frequency of readings
 */
std::string get_most_frequent(const std::vector<SensorData> &vect)
{
    std::unordered_map<std::string, int> frequency_map;

    for(auto elem : vect)
    {
        frequency_map[elem.id]++;
    }

    std::string most_frequent {0};
    int max_count {0};

    for(const auto& pair : frequency_map)
    {
        if(pair.second > max_count)
        {
            max_count = pair.second;
            most_frequent = pair.first;
        }
    }
    return most_frequent;
}

/* Function prints vector.
 */
void print_data(const std::vector<SensorData>& data_list)
{
    for(auto elem : data_list)
    {
        std::cout << elem.timestamp << " : " << elem.id << " : " << elem.value << "\n";
    }
}

int main()
{
    std::vector<SensorData> data_vect;

    // Create some test data
    data_ingestion(data_vect, 134513, "ABC123", 3.14);
    data_ingestion(data_vect,235959, "XYZ789", 2.718);
    data_ingestion(data_vect,204411, "ABC123", 3.14);
    data_ingestion(data_vect,235400, "XYZ789", 2.712);
    data_ingestion(data_vect,0100300, "DEF456", 10.618);
    data_ingestion(data_vect,195000, "XYZ789", 3.712);
    data_ingestion(data_vect,134513, "ABC123", 13.14);
    data_ingestion(data_vect,235959, "XYZ789", 22.315);
    data_ingestion(data_vect,130808, "DEF456", 1.648);
    data_ingestion(data_vect,235959, "XYZ789", 3.718);
    data_ingestion(data_vect,90808, "DEF456", 4.608);
     
    print_data(data_vect);
    std::cout << "Filtered:\n";
    std::vector<SensorData> filtered_data = filter_readings(data_vect, "ABC123");
    print_data(filtered_data);

    std::cout << "Sorted:\n";
    sort_data(filtered_data);
    print_data(filtered_data);
    std::vector<SensorData> outliers = detect_outliers(filtered_data);

    std::cout << "Ouliers:\n";
    print_data(outliers);

    std::cout << "Most frequent:\n";
    std::cout << get_most_frequent(data_vect);

    return 0;
}