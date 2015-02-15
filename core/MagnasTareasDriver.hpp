/* API for MagnasTareas Drivers */

typedef enum{
	LOCAL,
	GOOGLE_TASKS
} DriverName;

class MagnasTareasDriver {
public:
	MagnasTareasDriver();
	~MagnasTareasDriver();
	virtual bool IsEnabled();
protected:
	
};
