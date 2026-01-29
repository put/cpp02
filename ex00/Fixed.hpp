class Fixed {
    private:
    static const int FRAC_BIT_COUNT = 8;
    int _value;
    public:
    Fixed();
    Fixed(const Fixed& orig);
    Fixed& operator=(const Fixed& orig);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int raw);
};