#include <iostream>
using namespace std;
enum os {ios,android,windows_phone};
enum ram {gb2,gb4,gb6,gb8,gb12,gb16,gb32,gb64};
enum color{red,black,white};
class phone
{
    string name;
    string company;
    string os;
    int ram;
    float price;
    string color;
    int count;
    int cell_count;
public:
    phone ()
    {
        count=0;
        cell_count=0;
    }
    void set_name (string a)
    {
        name=a;
    }
    //-----------------
    void set_company (string a)
    {
        company=a;
    }
    //---------------------
    void set_os (string a)
    { 
        os=a;
    }

    void set_ram (int a)
    {
        ram=a;
    }

    void set_price (float a)
    {
        price=a;
    }

    void set_color (string a)
    {
        color=a;
    }

    void set_count (int a)
    {
        count=a;
    }

    void set_cell_count (int a)
    {
        cell_count=a;
    }

    string get_name ()
    {
        return name;
    }

    string get_company ()
    {
        return company;
    }

    string get_os ()
    {
        return os;
    }

    int get_ram ()
    {
        return ram;
    }

    float get_price ()
    {
        return price;
    }

    string get_color ()
    {
        return color;
    }

    int get_count ()
    {
        return count;
    }

    int get_cell_count ()
    {
        return cell_count;
    }

};
class shop
{
    phone * all_phone;
    int size_array;
public:
    int get_size ()
    {
        return size_array;
    }
    shop (int a=0)
    {
        size_array=a;
        all_phone=new phone [size_array];
    }
    void print_phones ()
    {
        for (int i=0;i<size_array;i++)
        {
            cout<<all_phone[i].get_name()<<" "<<all_phone[i].get_company()<<" "<<all_phone[i].get_os()<<" "<<all_phone[i].get_ram()<<" "<<all_phone[i].get_color()<<" "<<all_phone[i].get_count()<<" "<<all_phone[i].get_price()<<" "<<all_phone[i].get_cell_count()<<endl;
        }
    }
    void add_phone (phone a)
    {
        int s=0;
        for (int i=0;i<size_array;i++)
        {
            if (a.get_name()==all_phone[i].get_name()&&a.get_company()==all_phone[i].get_company())
            {
                s=1;
                break;
            }
        }
        if (s==0)
        {
            phone * komaki;
            komaki=new phone [size_array];
            for (int i=0;i<size_array;i++)
            {
                komaki[i]=all_phone[i];
            }
            size_array++;
            delete [] all_phone;
            all_phone=new phone [size_array];
            for (int i=0;i<size_array-1;i++)
            {
                all_phone[i]=komaki[i];
            }
            all_phone[size_array-1]=a;
            delete [] komaki;
        }
    }
    void add_phone (string a,string b,int c)
    {
        for (int i=0;i<size_array;i++)
        {
            if (a==all_phone[i].get_name()&&b==all_phone[i].get_company())
            {
                all_phone[i].set_count(all_phone[i].get_count()+c);
                break;
            }
        }
    }
    int search (string a,string b)
    {
        for (int i=0;i<size_array;i++)
        {
            if (a==all_phone[i].get_name()&&b==all_phone[i].get_company())
            {
                return i;
            }
        }
        return -1;
    }
    void remove_phone (int a)
    {
        if (a>=0&&a<size_array)
        {
            phone *komaki;
            komaki=new phone [size_array];
            for (int i=0;i<size_array;i++)
            {
                komaki[i]=all_phone[i];
            }
            delete [] all_phone;
            all_phone=new phone [size_array-1];
            for (int i=0;i<a;i++)
            {
                all_phone[i]=komaki[i];
            }
            for (int i=a;i<size_array-1;i++)
            {
                all_phone[i]=komaki[i+1];
            }
            delete [] komaki;
            size_array--;
        }
    }
    void sort_by_price ()
    {

        for (int i=0;i<size_array-1;i++)
        {
            for (int j=0;j<size_array-i-1;j++)
            {
                if (all_phone[j].get_price()>all_phone[j+1].get_price())
                {
                    phone a;
                    a=all_phone[j];
                    all_phone[j]=all_phone[j+1];
                    all_phone[j+1]=a;
                }
            }
        }
        print_phones();

    }
    void change_mobile_info (string a,string b)
    {
        for (int i=0;i<size_array;i++)
        {
            if (a==all_phone[i].get_name()&&b==all_phone[i].get_company())
            {
                cout<<"1.name\n2.company\n3.os\n4.color\n5.count\n6.cell_count\n7.ram\n8.price\n";
                int x;
                cin>>x;
                cin.get();
                if (x==1)
                {
                    string c;
                    cout<<"new: ";
                    cin>>c;
                    all_phone[i].set_name(c);
                }
                else if (x==2)
                {
                    string c;
                     cout<<"new: ";
                    cin>>c;
                    all_phone[i].set_company(c);
                }
                else if (x==3)
                {
                    string c;
                     cout<<"new: ";
                    cin>>c;
                    all_phone[i].set_os(c);
                }
                else if (x==4)
                {
                    string c;
                     cout<<"new: ";
                    cin>>c;
                    all_phone[i].set_color(c);
                }
                else if (x==5)
                {
                    int c;
                     cout<<"new: ";
                    cin>>c;
                    all_phone[i].set_count(c);
                }
                else if (x==6)
                {
                    int c;
                     cout<<"new: ";
                    cin>>c;
                    all_phone[i].set_cell_count(c);
                }
                else if (x==7)
                {
                    int c;
                     cout<<"new: ";
                    cin>>c;
                    all_phone[i].set_ram(c);
                }
                else if (x==8)
                {
                    float c;
                     cout<<"new: ";
                    cin>>c;
                    all_phone[i].set_price(c);
                }
            }
        }
    }
    void sell_phone (string a,string b)
    {
        for (int i=0;i<size_array;i++)
        {
            if (a==all_phone[i].get_name()&&b==all_phone[i].get_company())
            {
               if (all_phone[i].get_count()>0)
               {
                   all_phone[i].set_count(all_phone[i].get_count()-1);
                   all_phone[i].set_cell_count(all_phone[i].get_cell_count()+1);
               }
            }
        }
    }
    void namayesh (int i)
    {
        cout<<all_phone[i].get_name()<<" "<<all_phone[i].get_company()<<" "<<all_phone[i].get_count()<<" "<<all_phone[i].get_os()<<" "<<all_phone[i].get_ram()<<" "<<all_phone[i].get_color()<<" "<<all_phone[i].get_count()<<" "<<all_phone[i].get_price()<<" "<<all_phone[i].get_cell_count()<<endl;
    }
    void most_sold_item ()
    {
        phone * komaki;
        komaki=new phone [size_array];
        for (int i=0;i<size_array;i++)
        {
            komaki[i]=all_phone[i];
        }
        for (int i=0;i<size_array-1;i++)
        {
            for (int j=0;j<size_array-i-1;j++)
            {
                if (komaki[j].get_price()*komaki[j].get_cell_count()<komaki[j+1].get_price()*komaki[j+1].get_cell_count())
                {
                    phone a;
                    a=komaki[j];
                    komaki[j]=komaki[j+1];
                    komaki[j+1]=a;
                }
            }
        }
        for (int i=0;i<size_array;i++)
        {
            cout<<komaki[i].get_name()<<" "<<komaki[i].get_company()<<" "<<komaki[i].get_count()<<" "<<komaki[i].get_os()<<" "<<komaki[i].get_ram()<<" "<<komaki[i].get_color()<<" "<<komaki[i].get_count()<<" "<<komaki[i].get_price()<<" "<<komaki[i].get_cell_count()<<endl;
        }
    }




};

int main()
{
    shop kol;
    while (1)
    {
        cout<<"1.add\n2.remove\n3.sort by price\n4.search\n5.change\n6.sell\n7.print\n8.most sold\n9.exit\n";
        int x;
        cout<<"choose: ";
        cin>>x;
        cin.get();
        if (x==1)
        {
            phone a;
            string b;
            cout<<"name: ";
            cin>>b;
            a.set_name(b);
            string c;
            cout<<"company: ";
            cin>>c;
            a.set_company(c);
            string d;
            enum os {ios,android,windows_phone};
            cout<<"os: ";
            cin>>d;
            if (d=="ios" || d=="android"||d=="windows_phone")
            {
               a.set_os (d);
            }
            else{break;}
            string e;
            cout<<"color: ";
            cin>>e;
            enum color{red,black,white};
            if (e=="red"||e=="black"||e=="white")
            {
             a.set_color(e);
            }
            else{break;}
            int h;
            cout<<"ram: ";
            cin>>h;
            enum ram {gb2,gb4,gb6,gb8,gb12,gb16,gb32,gb64};
            if (h==2||h==4||h==6||h==8||h==12||h==16||h==32||h==64)
            {
               a.set_ram (h);
            }
            else{break;}
            float i;
            cout<<"price: ";
            cin>>i;
            a.set_price(i);
            kol.add_phone(a);
            int tedad;
            cout<<"tedad: ";
            cin>>tedad;
            kol.add_phone(b,c,tedad);
        }
        else if (x==2)
        {
            int xy;
            string a;
            string b;
            cout<<"name: ";
            cin>>a;
            cout<<"company: ";
            cin>>b;
            xy=kol.search(a,b);
            if (xy!=-1)
            {
                kol.remove_phone(xy);
            }
        }
        else if (x==3)
        {
            kol.sort_by_price();
        }
        else if (x==4)
        {
            string a;
            string b;
            cout<<"name: ";
            cin>>a;
            cout<<"company: ";
            cin>>b;
            int xy=kol.search(a,b);
            if (xy!=-1)
            {
                kol.namayesh(xy);
            }
        }
        else if (x==5)
        {
            string a;
            string b;
            cout<<"name: ";
            cin>>a;
            cout<<"company: ";
            cin>>b;
            kol.change_mobile_info(a,b);
        }
        else if (x==6)
        {
            string a;
            string b;
            cout<<"name: ";
            cin>>a;
            cout<<"company: ";
            cin>>b;
            kol.sell_phone(a,b);
        }
        else if (x==7)
        {
            kol.print_phones();
        }
        else if (x==8)
        {
            kol.most_sold_item();
        }
        else if (x==9)
        {
            break;
        }
        else
        {
            cout<<"invalid value\n";
        }
    }
    return 0;
}