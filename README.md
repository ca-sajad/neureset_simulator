## Neureset Direct Neurofeedback EEG Device Simulator

This is a device simluator designed and implemented by a team of 5 students for a course project. I contributed to this project by writing the documentation and the code of 
- Main use case 
- UML class diagram
- Design patterns report
- Implemented TestUI window
- Implemented TestUI class
- Implemented Device class
- Implemented WaveGenerator class
- Modified EEG class
- Modified timer and progress bar in MainWindow
- Critical fixes in MainWindow and SessionManager


### Project Overview

This project simulates the software for a hypothetical consumer EEG direct neurofeedback device called Neureset, based on the LENS Neurofeedback system. It aims to provide a software-based prototype for treating various conditions such as ADHD, PTSD, TBI, anxiety, and more, as well as optimizing brain function and cognitive performance. 

Neureset is intended as a standalone consumer device for direct neurofeedback, requiring no therapist intervention. It consists of an EEG headset connected to a handheld device, functioning both as a signal processor and user interface. The device calculates dominant frequencies, delivers treatments, and stores session data. For more information, refer to the [project specifications](https://github.com/ca-sajad/neureset_simulator/blob/main/DesignDoc/Neureset%20Team%20Project%20Specification.pdf).

The project implements the MVC design pattern ti support two GUIs, mainwindow.ui is the GUI which the user interacts with to use the device’s main functionality (below image, left), whereas testui.ui is the development GUI that the user can use to view the plots of waveforms (below image, right). testui.ui window is only displayed when the user starts a new session. 

<p>
	<img src="https://github.com/ca-sajad/neureset_simulator/blob/main/images/main_window_sample.png" alt="main window" width="500"/>
	<img src="https://github.com/ca-sajad/neureset_simulator/blob/main/images/test_ui_sample.png" alt="main window" width="500"/>
</p>

One of the extensions of use case 1 of the design document requires the application to pause the treatment session when the pause button is pressed by the user. Doing so involves running the device in a separate thread. Otherwise, when a treatment session starts, the GUI becomes irresponsive until the end of session making the pause and stop button irrelevant. 
In addition to the device, the instance of SessionManager needs to run in its own thread to make the GUIs accessible when a treatment session is in progress. 

### Prerequisites

-   Qt framework installed on your system.
-   A C++ development environment compatible with the Qt framework.
-   [Mermaid Markdown](https://marketplace.visualstudio.com/items?itemName=bierner.markdown-mermaid) - Vscode extension to run and view diagrams.

### Usage

1. **Turn the Device On**
2. **Start a New Session**: Select the 'New Session' option from the menu and press the play button. Ensure the EEG headset is properly connected.
3. **Session Progress**: Monitor the session progress through the timer and progress bar displayed on the device UI.
4. **Pause/Stop Session**: Sessions can be paused or stopped using the corresponding buttons. Paused sessions can be resumed unless stopped or terminated due to loss of contact.
5. **View Session Log**: Access the session log to review past sessions, including time and date.
6. **Upload Session Data**: Connect the device to a PC to upload and view detailed session data, including before and after dominant frequencies.

### Testing Guidelines

A waveform generator simulates realistic EEG waveforms for testing, covering four brainwave bands. The testing process involves:
-   Connecting to 21 EEG sites (7 for testing purposes).
-   Processing input waveforms, calculating dominant frequencies, and delivering treatments.
-   Adjusting therapy timing for quicker testing cycles.
-   Simulating connection losses and battery depletion scenarios.


