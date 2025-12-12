class Fixed
{
	private:
	int rawBits;
	static const int fixed_point = 8;

	public:
	Fixed();
	Fixed(const int raw);
	Fixed(const float  num);
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& src);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};