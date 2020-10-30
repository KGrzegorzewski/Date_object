

class Date
{
    private:
        unsigned day = 0;
        unsigned month = 0;
        int year = 0;
    
    public:
        Date();
        Date(unsigned day, unsigned month, int year);
        Date(const Date& source);

        //operatory na pozniej

        unsigned get_day() const;
        unsigned get_month() const;
        int get_year() const;

        void set_day(unsigned day);
        void set_month(unsigned month);
        void set_year(int year);

        friend std::ostream& operator<<(std::ostream& os, const Date& date);
};