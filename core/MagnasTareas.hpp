#ifndef MAGNASTAREAS_HPP
#define MAGNASTAREAS_HPP

#include <string>

/* The public API for GUI frontends. GUI frontends should only use this API */

class MagnasTareas {
	public:
		MagnasTareas();
		~MagnasTareas();
		std::string		GetVersion();
};

#endif
