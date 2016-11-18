#ifndef _NUMBERED_HPP_
#define _NUMBERED_HPP_

class numbered{
	public:
		friend void f(numbered n);
		
		numbered():mysn(++unique){ cout << "numbered() called! and the static member is : " << unique << endl; }
		numbered(const numbered &rhs):mysn(++unique) { cout << "numbered(const numbered &) called! and the static member is : " << unique << endl; }
			
		~numbered() { cout << "numbered() called! and the static member is : " << unique << endl; }
	private:
		int mysn;
		static int unique;
};

int numbered::unique = 0;
	
void f(numbered n){ cout << n.mysn << endl; }

#endif