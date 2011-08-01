 
 #ifndef HELLO_H_
 #define HELLO_H_
 
 #include <Wt/Whello>
 #include <Wt/WContainerWidget>
#include<Wt/WEnvironment>
#include<Wt/WApplication>
 
 using namespace Wt;
 
 namespace Wt {
   class WContainerWidget;
   class WText;
   class WPushButton;
   class WLineEdit;
   class WComboBox;
   class WFormWidget;
   class WInteractWidget;
   class WFileUpload;

 }
 
 
 class HelloApplication : public WApplication
 {
 public:
   HelloApplication(WContainerWidget *parent = 0);
 
 private:
   
 
 //  void submit(); 
 
   void createUI();
  
  
 
   
   WComboBox *sfile;
   WFileUpload *upload;
   WPushButton *submit;
   WPushButton *uploadButton;
 
 
 
  
   
 };
 #endif // HELLO_H_

