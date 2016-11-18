#ifndef _NUMBERED_HPP_
#define _NUMBERED_HPP_

class numbered{
	public:
		friend void f(numbered n);
		
		numbered(){ mysn = ++unique; }
	private:
		int mysn;
		static int unique;
};

int numbered::unique = 0;
	
void f(numbered n){ cout << n.mysn << endl; }

#endif