#include "wx/wx.h"

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

// defer closing the frame
class CloseFunctor {
public:
  wxFrame *frame;

  CloseFunctor(wxFrame *frame) { this->frame = frame; }

  void operator()(wxCommandEvent &event) {
    frame->Close();
    delete frame;
  }
};

// defer uppdating the number of clicks
class AboutFunctor {
public:
  wxFrame *frame;
  int numberOfAboutClicks;

  AboutFunctor(wxFrame *frame, int numberOfAboutClicks) {
    this->frame = frame;
    this->numberOfAboutClicks = numberOfAboutClicks;
  }

  void operator()(wxCommandEvent &event) {
    numberOfAboutClicks++;
    wxString msg;
    {
      msg.Printf(wxT("Hello, welcome to %s, clicked %d times"),
                 wxVERSION_STRING, numberOfAboutClicks);
    }
    wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, frame);
  }
};

bool MyApp::OnInit() {
  auto *frame = new wxFrame(nullptr, wxID_ANY, wxT("Minimal App"));

  auto *menuBar = new wxMenuBar();
  {
    auto *fileMenu = new wxMenu();
    {
      fileMenu->Append(wxID_EXIT, wxT("E&xit"), wxT("Quit"));
      frame->Bind(wxEVT_COMMAND_MENU_SELECTED, CloseFunctor(frame), wxID_EXIT);
      menuBar->Append(fileMenu, wxT("&File"));
    }
    auto *helpMenu = new wxMenu();
    {
      int numberOfAboutClicks = 0;
      helpMenu->Append(wxID_ABOUT, wxT("&About"), wxT("Show About Dialog"));
      frame->Bind(wxEVT_COMMAND_MENU_SELECTED,
                  AboutFunctor(frame, numberOfAboutClicks), wxID_ABOUT);
      menuBar->Append(helpMenu, wxT("&Help"));
    }
  }
  frame->SetMenuBar(menuBar);
  frame->CreateStatusBar(1);
  frame->SetStatusText(wxT("Welcome"));
  frame->Show(true);
  return true;
}

DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)
