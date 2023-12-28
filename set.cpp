#include <iostream>
#include <vector>
using namespace std;

class SET
{
public:
    // properties
    vector<int> v;
    // behavior
    SET()
    {
        //constructor
    }

    bool BelongsTo(int data) {
    int s = 0;
    int e = v.size() - 1;

    while (s <= e) {
        int mid1 = s + (e - s) / 3;
        int mid2 = e - (e - s) / 3;

        if (v[mid1] == data || v[mid2] == data) {
            return true;
        }

        if (data < v[mid1]) {
            e = mid1 - 1;
        } else if (data > v[mid2]) {
            s = mid2 + 1;
        } else {
            s = mid1 + 1;
            e = mid2 - 1;
        }
    }

    return false;
}

    void Insert(int data)
    {
        if (!BelongsTo(data))
        {
        auto it = lower_bound(v.begin(), v.end(), data);
        v.insert(it, data);
        }
    }

    void Size()
    {
        cout << v.size() << endl;
    }

    void Delete(int data)
    {
        if (!BelongsTo(data))
        {
            cout << v.size() << endl;
        }
        else
        {
            int index = 0;
            while (v[index] != data)
            {
                index++;
            }
            for (int i = index; i < v.size() - 1; i++)
            {
                v[i] = v[i + 1];
            }
            v.pop_back();
            cout << v.size() << endl;
        }
    }

    void print()
    {
        int i = 0;
        while (i < v.size() - 1)
        {
            cout << v[i] << ",";
            i++;
        }
        if(v.size()>0){
        cout << v[i];}
        cout << endl;
    }

void Intersection(SET p) {
    vector<int> a;
    
    for (int i = 0; i < v.size(); i++) {
        if (!p.BelongsTo(v[i])) {
            v.erase(v.begin() + i);
            i--; 
        }
    }
}

    void Union(SET p)
    {

        for (int i = 0; i < p.v.size(); i++)
        {
            int element = p.v[i];
            if(!BelongsTo(element)) {
               Insert(element);
            }
        }
    }


    void Difference(SET p)
    {
        for (int i = 0; i < p.v.size(); i++)
        {
            int element = p.v[i];
            if (BelongsTo(element))
            {
                int index = 0;
                while (v[index] != element)
                {
                    index++;
                }
                for (int i = index; i < v.size() - 1; i++)
                {
                    v[i] = v[i + 1];
                }
                v.pop_back();
            }
        }
    }

    void SymmetricDifference(SET p) {
    int index1 = 0;
    int index2 = 0;
    
    while (index1 < v.size() && index2 < p.v.size()) {
        if (v[index1] == p.v[index2]) {
            v.erase(v.begin() + index1);
            p.v.erase(p.v.begin() + index2);
        }
        else if (v[index1] < p.v[index2]) {
            index1 += 1;
        }
        else {
            index2 += 1;
        }
    }
    if (p.v.size() > 0) {
        for (int i = 0; i < p.v.size(); i++) {
            int element = p.v[i];
            if (!BelongsTo(element)) {
                Insert(element);
            }
        }
    }
}

    
};

int main()
{
    vector<SET> sets;
    while (true)
    {
        int operation, setIndex, data;
        cin >> operation;
        if(!cin) {
            break;
        }
        switch (operation)
        {
        case 1:
            cin >> setIndex;
            cin >> data;
            if (setIndex >= sets.size())
            {
                sets.push_back(SET());
            }
            sets[setIndex].Insert(data);
            cout << sets[setIndex].v.size() << endl;
            break;

        case 2:
            cin >> setIndex;
            cin >> data;
            if (setIndex >= sets.size())
            {
                cout << "-1" << endl;
            }
            else
            {
                sets[setIndex].Delete(data);
            }
            break;

        case 3:
            cin >> setIndex;
            cin >> data;
            if (setIndex >= sets.size())
            {
                cout << "-1" << endl;
            }
            else if (sets[setIndex].BelongsTo(data))
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
            break;

        case 4:
            cin >> setIndex;
            cin >> data;
            if (setIndex >= sets.size()) {
            sets.push_back(SET());
            }
            if (data >= sets.size()) {
            sets.push_back(SET());
            }
            if(setIndex == data) {
                cout << sets[setIndex].v.size() << endl;
             }
            else {
            sets[setIndex].Union(sets[data]);
            cout << sets[setIndex].v.size() << endl;
            }
            break;

        case 5:
            cin >> setIndex;
            cin >> data;
            if (setIndex >= sets.size()) {
            sets.push_back(SET());
            }
            if (data >= sets.size()) {
            sets.push_back(SET());
            }
            sets[setIndex].Intersection(sets[data]);
            cout << sets[setIndex].v.size() << endl;
            break;

        case 6:
            cin >> setIndex;
            if (setIndex >= sets.size())
            {
                sets.push_back(SET());
                cout << "0" << endl;
            }
            else
            {
                cout << sets[setIndex].v.size() << endl;
            }
            break;

        case 7:
            cin >> setIndex;
            cin >> data;
            if (setIndex >= sets.size())
            {
                sets.push_back(SET());
            }
            if (data >= sets.size())
            {
                sets.push_back(SET());
            }
            sets[setIndex].Difference(sets[data]);
            cout << sets[setIndex].v.size() << endl;
            break;

        case 8:
            cin >> setIndex;
            cin >> data;
            if (setIndex >= sets.size()) {
                sets.push_back(SET());
            }
            if (data >= sets.size()) {
                sets.push_back(SET());
            }
            if(setIndex == data) {
            sets[setIndex].v.clear();
            sets[data].v.clear();
            }
            else {
            sets[setIndex].SymmetricDifference(sets[data]);
            }
            cout << sets[setIndex].v.size() << endl;
            break;

        case 9:
            cin >> setIndex;
            if (setIndex >= sets.size())
            {
                cout << endl;
            }
            else if(sets[setIndex].v.size() == 0) {
                cout << endl;
            }
            else
            {
                sets[setIndex].print();
            }
            break;

        default:
            break;
        }
    }
}