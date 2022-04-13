#include <iostream>
#include <string>


using namespace std;

class Time {

public:

//    Time(){}

    Time(int s=0)
     {
      time = s;
     }

    void set_time(int s)
     {
      time = s;
     }

    string get_time()
     {
      string stime;
      int ttime = time;

      if (ttime <= 32400){stime = stime + "0";}
      stime = stime + to_string((int)ttime/3600) + "h:";
      ttime = ttime % 3600;

      if (ttime <= 540){stime = stime + "0";}
      stime = stime + to_string((int)ttime/60) + "m:";
      ttime = ttime % 60;

      if (ttime <= 9){stime = stime + "0";}
      stime = stime + to_string((int)ttime) + "s";

      return stime;
     }

    int get_time_debug()
     {
      return time;
     }

//    Time add(Time other)
//     {
//      return Time(time + other.time);
//     }

    Time operator+(const Time &rhs)
     {
      return Time(time + rhs.time);
     }

    Time operator-(const Time &r)
     {
      return time - r.time;
     }

    Time operator*(const int &r)
     {
      return time*r;
     }

    friend ostream &operator<<(ostream &out, Time &rhs)
    {
     return out << rhs.get_time();
    }

    friend istream &operator>>(istream &in, Time &rhs)
     {
      int h, m, s;
      cout << "Enter number of hours" <<endl;
      in >> h;
      cout << "Enter number of minutes" <<endl;
      in >> m;
      cout << "Enter number of seconds" <<endl;
      in >> s;
      if(h>=60){h=59;}
      if(m>=60){m=59;}
      if(s>=60){s=59;}
      rhs.time = (s+60*m+3600*h);
      return in;
     }

    operator int()
     {
      return (int)time;
     }


//    int num() const; // gets numerator
//    int den() const; // gets denominator
//    void set_num(int num); // sets numerator
//    void set_den(int den); // sets denominator
//    Rational add(const Rational &other) const; // adds second rational number, returns result
//    Rational subtract(const Rational &other) const; // subtracts second rational number, returns result
//    void print() const; // prints number to console

private:
    int time;
};

int main()
{
//    Time t1(200);
//    cout << t1 << endl;
//    Time t2(300);
//    cout << t2 << endl;

//    Time t3;
//    cin >> t3;
//    cout << t3 << endl;

//    Time t5 = (t2 - t1);
//    cout << t5 << endl;

    Time t1(200);
    cout << t1 << endl; // displays 03m:20s
    Time t2;
    cin >> t2; // user enters 10h:12m:01s
    cout << t2 << endl;

    Time t3 = t2 - t1; // 10h:8m:41s
    int t3s = t3; // 36521
    cout << t3s << endl;
}
