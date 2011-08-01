/**
	Folder:		$ mkdir /tmp/wt/; cd /tmp/wt/
	Git:			$ git clone git@gitorious.org:wt/tests.git
						$ cd tests/wt/TriggeringEvent/
	Compile:	$ cmake -DEXAMPLES_CONNECTOR="wt;wthttp"
						$ make
	Run: 			$ ./test.wt --docroot . --http-addr 0.0.0.0 --http-port 10100
*/

#include <boost/thread.hpp>
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WStackedWidget>
#include <Wt/WWidget>
#include <Wt/WTemplate>
#include <Wt/WMenu>
#include <Wt/WDateTime>
#include <Wt/WText>
#include <Wt/WBreak>
#include <Wt/WGridLayout>
#include <Wt/WImage>
using namespace std;
using namespace Wt;

// *********************************************************************************************************************
/** Create Page Deferred - Class */
template <typename Function>
class DeferredWidget : public Wt::WContainerWidget {
	private:
		Function f_;

		void load() {
			Wt::WContainerWidget::load();
			if (count() == 0) addWidget(f_());
		}

	public:
		DeferredWidget(Function f) : f_(f) { }
};

/** Create Page Deferred - Template */
template <typename Function>
DeferredWidget<Function>* deferCreate(Function f) { return new DeferredWidget<Function>(f); }

// *********************************************************************************************************************

/** 2 others classes: Home & About */
class Home : public Wt::WContainerWidget {
	private:
	public:
		Home();
		virtual ~Home();
};

Home::Home() {
	
Wt::WContainerWidget *p = new Wt::WContainerWidget(this);
 p->resize(WLength::Auto, 200);

 Wt::WGridLayout *lay = new Wt::WGridLayout();
//lay->addWidget(new Wt::WText("this site is made by parvinder rajput. \n who are pursuing is b.tech from gndec ludhiana."),0,0);
// lay->addWidget(new Wt::WText("this is dean of consultancy cell"), 0, 2);
 //lay->addWidget(new Wt::WText("Hello"), 0, 0);
 
//lay->addWidget(new Wt::WImage("/images/Footer.jpg"), 0,0);
lay->addWidget(new Wt::WText("HERE GOES A SMALL RHYMES WEBSITE FOR NURSERY KIDS TO MAKE THEIR LEARNING INTERESTING."), 0,0);
lay->addWidget(new Wt::WImage("/images/images.jpeg"), 0,2);
lay->addWidget(new Wt::WImage("/images/images8.jpeg"), 0,1);
p->setLayout(lay);
}

Home::~Home() {
	// delete this; // dont work to refresh page
}

// *****************************************************************************

class About : public Wt::WContainerWidget {
	private:
	public:
std::string store;
		About();
		virtual ~About();
};

About::About() {
	WContainerWidget *cw = new 	WContainerWidget();
	
	cw->addWidget(new WBreak());
	cw->addWidget(new WBreak());

	
	this->addWidget(cw);
Wt::WContainerWidget *j = new Wt::WContainerWidget(this);
 j->resize(WLength::Auto, 200);

Wt::WGridLayout *lay = new Wt::WGridLayout();
store="<p>jonny jonny yes papa," 
      " Eating sugar no papa "
      "Telling lie, no papa " 
      "Open your mouth .</p>haha. ";


//lay->addWidget(new Wt::WText("this site is made by parvinder rajput. \n who are pursuing is b.tech from gndec ludhiana."),0,0);
// lay->addWidget(new Wt::WText("this is dean of consultancy cell"), 0, 2);
 //lay->addWidget(new Wt::WText("Hello"), 0, 0);
 
//lay->addWidget(new Wt::WImage("/images/Footer.jpg"), 0,0);
lay->addWidget(new Wt::WText(store ), 0,3);
lay->addWidget(new Wt::WImage("/images/jj.jpg"), 0,0);
lay->addWidget(new Wt::WImage("/images/uu.gif"), 0,2);
j->setLayout(lay); 
}

About::~About() {
	// delete this; // dont work to refresh page
}

// *********************************************************************************************************************

/** Wt Class */
class WtApplication : public WApplication {
	private:
		void msg(string str);
		Wt::WWidget *menuHome();
		Wt::WWidget *menuAbout();
		Wt::WTemplate *staticPage(std::string str);

	public:
		WtApplication(const WEnvironment& env);
};

/** Wt Session Start */
WtApplication::WtApplication(const WEnvironment& env) : WApplication(env) {
	msg("");
useStyleSheet("css/style.css");
	msg("");

	WStackedWidget *sw = new WStackedWidget();
	WMenu *mn = new WMenu(sw, Horizontal, 0);
	mn->setRenderAsList(true); mn->setInternalPathEnabled();

	mn->addItem("Home Page", deferCreate(boost::bind(&WtApplication::menuHome, this)))->setPathComponent("Home");
	mn->addItem("RHYMES", deferCreate(boost::bind(&WtApplication::menuAbout, this)))->setPathComponent("About");

	root()->addWidget(mn);
	root()->addWidget(sw);
	
	msg("<p>&nbsp;</p>THANKS FOR VISIT.");
}

WWidget* WtApplication::menuHome() { return new Home(); }

WWidget* WtApplication::menuAbout() { return new About(); }

void WtApplication::msg(string str) {
	root()->addWidget(new WText(str));
	root()->addWidget(new WBreak());
}

// *********************************************************************************************************************

void mThread() {
	for (;;) {
		std::cout << "Delete old posted msgs from database" << std::endl; // after update DB, I would like (trigger) updating Home contents
		
		// how to update Home (for all sessions)?
		
		sleep(10);
	}
}

WApplication *createApplication(const WEnvironment& env) { return new WtApplication(env); }

int main(int argc, char **argv) {
	boost::thread t1(mThread);
	
	return WRun(argc, argv, &createApplication);
}
