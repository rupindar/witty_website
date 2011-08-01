#define POSTGRES // POSTGRES / SQLITE
#include <string>
#include <Wt/WString>
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/Dbo/Dbo>
#include <Wt/WDateTime>
#include <Wt/WText>
#include <Wt/WBreak>
#include <Wt/WStringListModel>
#include <Wt/WApplication>
#include <Wt/WGridLayout>
#include <Wt/WBorderLayout>
#include <Wt/WText>
#include <Wt/WHBoxLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WAnchor>
#include <Wt/WMessageBox>
#include <Wt/WImage>
#include <iostream>
#ifdef POSTGRES
#include <Wt/Dbo/backend/Postgres>
#endif
using namespace std;
using namespace Wt;
using namespace Wt::Dbo;

class A ;

typedef ptr<A> ptrA;                           /*The typedef keyword can be followed by any C++ built-in data type, including int, short, 
                                                 signed, unsigned, char, signed char, unsigned char, double, long, or long double.*/
typedef collection< ptrA > colA;         //This is an STL-compatible container that is backed by an SQL query for fetching data.
class A  {
public:
std::string store;

colA Bs;
template<class Action>
void persist(Action& a) {          /*The library defines a number of actions which will be applied to a database object using its persist()
                                     method, which applies it in turn to all its members. These actions will then read, update or insert 
                                    database objects, create the schema, or propagate transaction outcomes.*/

field(a, store, "dat");
    }
public:
		
};

class WtApplication  : public WApplication , public A {



	private:
#ifdef POSTGRES
    backend::Postgres connection_;
#endif
Session session_;
                 void image(); 
                 void link(); 
                 void sidebar();               //function decleration
		 void msg(string str);
	        //void populate();
		 void listAB();
                

public:
		WtApplication(const WEnvironment& env);
};
WtApplication::WtApplication(const WEnvironment& env) : WApplication(env), 
#ifdef POSTGRES
		connection_("host=127.0.0.1 user=pinder1 password=pinder1 port=5432 dbname=test12")
#endif

{
useStyleSheet("css/default.css");
	//msg("<b>database Relationship</b>");
        connection_.setProperty("show-queries", "true");           //show-queries: when value is "true", queries are shown as they are executed. 
	session_.setConnection(connection_);                          //It  manages an active transaction, which you need to access database objects.
	session_.mapClass<A>("a");

	try { Transaction tt(session_);
		session_.createTables();
		tt.commit();
	} catch (Exception &e) { cerr << "Exception: " << e.what() << endl; }
	image();
        link();
        sidebar();
        //populate();
	listAB();
}
void WtApplication::image()
{
Wt::WContainerWidget *j = new Wt::WContainerWidget(root());
 j->resize(WLength::Auto, 250);
 Wt::WBorderLayout *lat = new Wt::WBorderLayout();
 lat->addWidget(new Wt::WImage("/images/logo.png "),Wt::WBorderLayout::Center);
 j->setLayout(lat);
//StandardButton
  // result = WMessageBox::show("WELCOME USERS", " Please click ok to see TCC WEBSITE ",
                        //      Ok );
//WCssDecorationStyle& decoration=root()->decorationStyle();

      //decoration.setBackgroundColor(WColor("white "));
     //decoration.setForegroundColor(black);
 setTitle("Website");
// root()->setId("body");
//root()->setId("h1");
//root()->setId("body");
root()->addWidget( new WText("<h1>TRAINING AND CONSULTANCY CELL</h1>"));
}
void WtApplication::link()
 { 


Wt::WContainerWidget *l = new Wt::WContainerWidget(root());
  l->resize(WLength::Auto, 50);
 Wt::WHBoxLayout *layou = new Wt::WHBoxLayout();
 layou->addWidget(new Wt::WAnchor("http://gndec.ac.in/~tcc/", "INTRODUCTION", root()));
 layou->addWidget(new Wt::WAnchor("http://gndec.ac.in", "GNDEC", root()));
layou->addWidget(new Wt::WAnchor("http://parvinder.co.in/", "parvinder", root()));
layou->addWidget(new Wt::WAnchor("http://gndec.ac.in/~tcc/", "About us", root()));
 l->setLayout(layou);
//l->setId("center");
	
}
void WtApplication::sidebar()
{
Wt::WContainerWidget *p = new Wt::WContainerWidget(root());
  p->resize(WLength::Auto, 30);
 Wt::WHBoxLayout *lay = new Wt::WHBoxLayout();
 lay->addWidget(new Wt::WText("About TCC", root()));
 

 p->setLayout(lay);
//p->setId("sidebar");
}
/*void WtApplication::populate() {
	//insertion
	std::string strl;
strl = "<p>Consultancy Services are being rendered by various Departments of the College to the industry," 
      " Sate Government Departments and Entrepreneurs and are extended in the form of expert advice in "
      "design, testing of materials & equipment, technical surveys, technical audit, caliberation of " 
      " instruments, prepartion of technicalfeasibility reports etc.</p> This consultancy cell of the college has given a new dimension to the development programmes of the College. Consultancy projects of over Rs. one crore are completed by the Consultancy cell during financial year 2009-10. ";
	ptrA a;
	{ A *tuple = new A();
			tuple->store  =  Wt::WString(strl).toUTF8();
                         
                     try { Transaction tt(session_);
                      a = session_.add(tuple);
			tt.commit();
		    } catch (...) {}

  }
}
*/
 void WtApplication::listAB() { //fetching
                                       msg("<center><H1></H1></center>");

	try {
		Transaction tt(session_);
		colA collect = session_.find<A>();
               
		for (colA::const_iterator i = collect.begin(); i != collect.end(); ++i)

			msg((*i)->store);

		      tt.commit();
	              } catch (...) {}

}
WApplication *createApplication(const WEnvironment& env) { 

return new WtApplication(env); 

}

