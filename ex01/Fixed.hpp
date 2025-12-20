#include <ostream>

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
	~Fixed();
	Fixed& operator=(const Fixed& src);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int get_point();
};

std::ostream& operator<<(std::ostream& os, const Fixed& n);