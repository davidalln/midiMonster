#pragma once

#include "ofMain.h"

class mmLog {
	private:
		stringstream message;
		std::string module;

		void log();

	public:	
		mmLog(const std::string & _module = "n/a");
		mmLog(const mmLog & a);
		~mmLog();

		std::string getModuleName() const;

		template <class T>
			mmLog & operator<<(const T& value) {
				message << value;
				return *this;
			}

		mmLog & operator<<(std::ostream& (*func)(std::ostream&)) {
			func(message);
			return *this;
		}
};


