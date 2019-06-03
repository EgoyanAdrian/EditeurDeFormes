#ifndef POINT_HPP
#define POINT_HPP

typedef unsigned int uint;

template <typename ...> class Point;	// Multiple typename on a same class

template <typename Screen, typename Color>
class Point<Screen, Color> {
		uint x, y, size;	// Pos and Radius
		Color def, hov, sel;// Default, Hover and Selected Color
		bool selected;		// Selected by the user

	public:
	//Constructor and Destructor
		Point(uint _x, uint _y, Color _def, Color _hov, Color _sel);
		Point(uint _x, uint _y); // Simpler usage but color need to be set separatly
		Point(Point & _orig);
		//Point(istream & is); TO DO
		Point() = delete;
		~Point();

	// Getter & Setter
		inline void setX(uint _x) { x = _x;}
		inline uint getX() const { return x;}

		inline void setY(uint _y) { y = _y;}
		inline uint getY() const { return y;}

		inline void setDef(Color _def) { def = _def;}
		inline Color getDef() const { return def;}

		inline void setHov(Color _hov) { hov = _hov;}
		inline Color getHov() const { return hov;}

		inline void setSel(Color _sel) { sel = _sel;}
		inline Color getSel() const { return sel;}		

		inline void setSize(uint _size) { size = _size;}
		inline uint getSize() const { return size;}

		inline void setSelected(bool _selected) { selected = _selected;}
		inline bool getSelected() const{ return selected;}

	// Other methods
		inline bool isOver(uint _x, uint _y) const { return ((x <= _x && _x <= x + 2*size) && (y <= _y && _y <= y + 2*size));}
		inline virtual void draw(Screen & fenetre, bool isActive = false) const { };	// Depends on the tools to draw Empty by default
		inline virtual void update(uint _x, uint _y) { };
};

template <typename Screen, typename Color>
Point<Screen, Color>::Point(uint _x, uint _y, Color _def, Color _hov, Color _sel)
:x(_x), y(_y), size(6), def(_def), hov(_hov), sel(_sel), selected(false)
{ }

template <typename Screen, typename Color>
Point<Screen, Color>::Point(uint _x, uint _y)
:x(_x), y(_y), size(6), selected(false)
{ }

template <typename Screen, typename Color>
Point<Screen, Color>::Point(Point & _orig)
:Point(_orig.getX(), _orig.getY(), _orig.getSelected(), _orig.getDef(), _orig.getHov(), _orig.getSel())
{ }

template <typename Screen, typename Color>
Point<Screen, Color>::~Point()
{ }

#endif