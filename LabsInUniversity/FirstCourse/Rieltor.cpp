#include <iostream>
#include <vector>

using namespace std;

struct house
{
    double square;
    int badrooms;
    int bathrooms;
    int distance_To_Metro;
    bool comercial;
    double target;
};
vector<house> list_Of_Houses;

void input_Information_About_Houses();
bool sanity_check(house check_It);
double predict_Target(vector<house> educational, double square, int badrooms, int bathrooms, int distance_To_Metro, bool comercial);
void print_List_Of_Houses(vector<house> list);

int main()
{
    while (true)
    {
        char what_to_do;
        cout << "\nWhat do u want to do?\n1 - add Elements/predict\n2 - print List Of Houses\ns - stop program\n";
        cin >> what_to_do;
        switch (what_to_do)
        {
        case '1':
            input_Information_About_Houses();
            break;
        case '2':
            print_List_Of_Houses(list_Of_Houses);
            break;
        case 's':
            return 0;
            break;
        default:
            cout << "This variant doesn`t exist";
            break;
        }
    }
    return 0;
}

void input_Information_About_Houses()
{
    house new_House;
    while (true)
    {
        cout << "\nSquare\nIf u want to stop, then write 0:";
        cin >> new_House.square;
        if (new_House.square == 0)
            break;

        cout << "Badrooms:";
        cin >> new_House.badrooms;

        cout << "Bathrooms:";
        cin >> new_House.bathrooms;

        cout << "Distance to Metro in minutes:";
        cin >> new_House.distance_To_Metro;
        
        int check_bool=1;
        cout << "Is it commercial?\n1 if its. 0 if it isn`t:";
        cin >> check_bool;
        if (check_bool == 0 || check_bool == 1)// При введені поганого значення Bool, код ламається.
            new_House.comercial = check_bool;
        else
        {
            cout << "It`s not 1 or 0. It will be set up as 1\n";
            new_House.comercial = 1;
        }

        cout << "Target\nIf u want to predict, then input 0:";
        cin >> new_House.target;
        if (new_House.target == 0)
            new_House.target = predict_Target(list_Of_Houses, new_House.square, new_House.badrooms, new_House.bathrooms, new_House.distance_To_Metro, new_House.comercial);


        if (sanity_check(new_House) == 1)
            list_Of_Houses.push_back(new_House);
        else
            cout << "Something is wrong. Try again";
    }
    cout << "\n\nEnd of inputing.";
}
bool sanity_check(house check_It)
{
    if ((check_It.badrooms>=1 && check_It.badrooms<=10)
        && (check_It.bathrooms>=1 && check_It.bathrooms<=10)
        && (check_It.distance_To_Metro>=1 && check_It.distance_To_Metro<=60)
        && (check_It.square>=20 && check_It.square<=1000)
        && (check_It.target>=200 && check_It.target<=1000000))
        return 1;
    else
        return 0;
}
double predict_Target(vector<house> educational, double square, int badrooms, int bathrooms, int distance_To_Metro, bool comercial)
{
    if (educational.size() == 0)
    {
        cout << "Cannot predict. Education vector is empty.";
        return 0; // 0 призведе до того що sanity_check поверне 0. Відповідно нерухомість не додастся до вектору
    }

    int sum_Square=0;
    int sum_Distance=0;
    double sum_Target=0;
    for (int i = 0; i < educational.size(); i++)
    {
        sum_Target += educational[i].target;
        sum_Distance += educational[i].distance_To_Metro;
        sum_Square += educational[i].square;
    }
    //Якась Формула для обрахунку
    const double price_of_1square = sum_Square/sum_Target;
    const double price_of_1distance = sum_Distance / sum_Target;
    const float distance_Coefficient = (sum_Distance/educational.size())/(sum_Target/educational.size()); //  (середня відстань/середня ціна)
    const float square_Coefficient = 1/((sum_Square/educational.size()) / (sum_Target / educational.size())); // 1/(середня площа/середня ціна)
    const int comercial_Coefficient = comercial ? 5 : 1;// Комерція - дорожче в 5 раз

    double predicted_number = ((double)distance_To_Metro * distance_Coefficient * price_of_1distance + square * square_Coefficient * price_of_1square) * comercial_Coefficient; //distance_To_Metro int, що може призвезти до помилок. Переведемо у double
    cout << "Predicted:" << predicted_number << "\n";
    return predicted_number;
}
void print_List_Of_Houses(vector<house> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << "House " << i << "\n";
        cout << "Square:" << list[i].square << "\n";
        cout << "Badrooms:" << list[i].badrooms << "\n";
        cout << "Bathrooms:" << list[i].bathrooms << "\n";
        cout << "Distance to metro in minutes:" << list[i].distance_To_Metro << "\n";
        cout << "Comercial:" << list[i].comercial ? "Yes" : "No";
        cout << "\n";
        cout << "Target" << list[i].target << "\n\n";
    }
}
