#include "wx/wx.h"
#include <memory>

class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};

bool MyApp::OnInit(){
  auto frame = new wxFrame(nullptr,
                           wxID_ANY,
                           wxT("Minimal App"));


  auto numberOfAboutClicks = std::make_shared<int>(0);

  auto menuBar = new wxMenuBar();{
    auto fileMenu = new wxMenu();{
      fileMenu->Append(wxID_EXIT,
		       wxT("E&xit"),
		       wxT("Quit"));
      frame->Bind(wxEVT_COMMAND_MENU_SELECTED,
		  [=](wxCommandEvent& event){
                    std::cout << "About button clicked "
                              << *numberOfAboutClicks
                              << " times"
                              << std::endl;
		    frame->Close();
		    delete frame;
		  },
		  wxID_EXIT);
      menuBar->Append(fileMenu, wxT("&File"));
    }
    auto * helpMenu = new wxMenu();{
      helpMenu->Append(wxID_ABOUT,
		       wxT("&About"),
		       wxT("Show About Dialog"));
      frame->Bind(wxEVT_COMMAND_MENU_SELECTED,
		  [=](wxCommandEvent& event) mutable{
                    (*numberOfAboutClicks)++;
                    wxString msg;{
                      msg.Printf(wxT("Hello, welcome to %s, clicked %d times"),
                                 wxVERSION_STRING,
                                 *numberOfAboutClicks);
                    }
		    wxMessageBox(msg,
				 wxT("About Minimal"),
				 wxOK | wxICON_INFORMATION,
				 frame);
		  },
		  wxID_ABOUT);
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
