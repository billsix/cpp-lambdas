
#include "wx/wx.h"

class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};

class MyFrame: public wxFrame {
public:
  MyFrame(const wxString& title);

  void OnQuit(wxCommandEvent& e);
  void OnAbout(wxCommandEvent& e);

private:

  int numberOfAboutClicks;

  DECLARE_EVENT_TABLE()
};


bool MyApp::OnInit(){
  MyFrame * frame = new MyFrame(wxT("Minimal App"));
  frame->Show(true);
  return true;
}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
  EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
  EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent& e){
  numberOfAboutClicks++;

  wxString msg;
  msg.Printf(wxT("Hello, welcome to %s, clicked %d times"),
             wxVERSION_STRING,
             numberOfAboutClicks);
  wxMessageBox(msg,
	       wxT("About Minimal"),
	       wxOK | wxICON_INFORMATION,
	       this);
}

void MyFrame::OnQuit(wxCommandEvent& e){
  Close();
}

MyFrame::MyFrame(const wxString& title)
  :wxFrame(NULL, wxID_ANY, title){

  wxMenu * fileMenu = new wxMenu();
  wxMenu * helpMenu = new wxMenu();

  fileMenu->Append(wxID_EXIT,
		   wxT("E&xit"),
		   wxT("Quit"));

  helpMenu->Append(wxID_ABOUT,
		   wxT("&About"),
		   wxT("Show About Dialog"));

  wxMenuBar * menuBar = new wxMenuBar();
  menuBar->Append(fileMenu, wxT("&File"));
  menuBar->Append(helpMenu, wxT("&Help"));

  SetMenuBar(menuBar);
  CreateStatusBar(1);
  SetStatusText(wxT("Welcome"));

  numberOfAboutClicks = 0;

}


DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)
