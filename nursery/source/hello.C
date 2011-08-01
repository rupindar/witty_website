#include <Wt/WMenu>
#include <Wt/WStackedWidget>
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WTableView>
#include <Wt/WContainerWidget>
#include <Wt/WBorderLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WText>
#include <Wt/WHBoxLayout>
#include <Wt/WBoxLayout>
#include <Wt/WAnchor>
#include <Wt/WTreeTable>
#include <Wt/WImage>

using namespace Wt;
using namespace std;
class HelloApplication : public WApplication

{
public:
  HelloApplication(const WEnvironment& env);
 std::string store;
};
HelloApplication::HelloApplication(const WEnvironment& env)
  : WApplication(env)
{
  setTitle("Rupinder"); 
// Wt::WContainerWidget *h= new Wt::WContainerWidget(root());
//  h->resize(WLength::Auto, 50);
 //Wt::WHBoxLayout *layom = new Wt::WHBoxLayout();
 Wt::WContainerWidget *p = new Wt::WContainerWidget(root());
 p->resize(WLength::Auto, 200);

 Wt::WGridLayout *lay = new Wt::WGridLayout();
//lay->addWidget(new Wt::WText("this site is made by parvinder rajput. \n who are pursuing is b.tech from gndec ludhiana."),0,0);
// lay->addWidget(new Wt::WText("this is dean of consultancy cell"), 0, 2);
 //lay->addWidget(new Wt::WText("Hello"), 0, 0);
 
lay->addWidget(new Wt::WImage("/images/Footer.jpg"), 0,0);
lay->addWidget(new Wt::WText("WELCOME "), 0, 3);
lay->addWidget(new Wt::WImage("/images/images.jpeg"), 0,6);
p->setLayout(lay); 
Wt::WContainerWidget *l = new Wt::WContainerWidget(root());
  l->resize(WLength::Auto, 100);
 Wt::WHBoxLayout *layo = new Wt::WHBoxLayout();
 layo->addWidget(new Wt::WAnchor("http://gndec.ac.in/~tcc/", "INTRODUCTION", root()));
 layo->addWidget(new Wt::WAnchor("http://gndec.ac.in", "GNDEC", root()));
//WCssDecorationStyle& decoration=root()->decorationStyle();

  //    decoration.setBackgroundColor(WColor("#00FFFF"));
    //  decoration.setForegroundColor(black);
useStyleSheet("css/style.css");
layo->addWidget(new Wt::WAnchor("http://rupjat.com/", "RUPINDER", root()));


//layo->addWidget(new Wt::WImage("images/images.jpeg1", root()));


 /*layo->addWidget(new Wt::WText(store));
 layo->addWidget(new Wt::WImage("/images/rai.jpeg ", root()));*/
 l->setLayout(layo, AlignTop | AlignJustify);
 root()->addWidget(new WText("<h1><center>CHILDHOOD DAYS</center></h1> "));
store="<p>jonny jonny yes papa," 
      " Eating sugar no papa "
      "design, testing of materials & equipment, technical surveys, technical audit, caliberation of " 
      " instruments, prepartion of technicalfeasibility reports etc.</p> This consultancy cell of the college has given a new dimension to the development programmes of the College. Consultancy projects of over Rs. one crore are completed by the Consultancy cell during financial year 2009-10. ";


// Wt::WContainerWidget *w = new Wt::WContainerWidget(root());
// w->resize(WLength::Auto,50);


 

 // Wt::WContainerWidget *f = new Wt::WContainerWidget(root());
// f->resize(WLength::Auto, 50);

// Wt::WGridLayout *layb= new Wt::WGridLayout();
//lay->addWidget(new Wt::WText("this site is made by parvinder rajput. \n who are pursuing is b.tech from gndec ludhiana."),0,0);
//lay->addWidget(new Wt::WText("this is dean of consultancy cell"), 0, 2);
 
 //f->setLayout(layb); 
 Wt::WContainerWidget *j = new Wt::WContainerWidget(root());
j->resize(WLength::Auto,400);

 Wt::WBorderLayout *lati = new Wt::WBorderLayout();
// lati->addWidget(new Wt::WText("r"), Wt::WBorderLayout::West);
//decoration.setBackgroundColor(WColor(white));
  lati->addWidget(new Wt::WImage("images/images.jpeg1"), Wt::WBorderLayout::East);
 lati->addWidget(new Wt::WText(store), Wt::WBorderLayout::Center);
 
 // use layout but do not justify vertically
 j->setLayout( lati, Wt::AlignTop | Wt::AlignJustify);

}
WApplication *createApplication(const WEnvironment& env)
{
 
  return new HelloApplication(env);
}

int main(int argc, char **argv)
{
 
  return WRun(argc, argv, &createApplication);
}

