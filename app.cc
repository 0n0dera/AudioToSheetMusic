#include "MidiFile.h"
#include "Options.h"
#include <iostream>

int main(int argc, char** argv)
{
	Options options;
	options.process(argc, argv);
	if (options.getArgCount() != 1)
	{
		std::cerr << "Usage: ./app <midi file>\n";
		exit(1);
	}
	MidiFile midifile;
	midifle.read(options.getArg(1));
	if (!midifile.status())
	{
		std::cerr << "Error reading MIDI file " << options.getArg(1) << std::endl;
		exit(1);
	}
	midifile.joinTracks();
	int track = 0;
	for (int i=0; i<midifile[track].size(); ++i)
	{
		if (!midifile[track][i].isNoteOn())
		{
			continue;
		}
		std::cout << midifile[track][i].time << '\t' 
				  << midifile[track][i][1]   << std::endl;
	}
}