namespace logsystem
{
	enum tipy_debug
	{
		DEBUG,
		WARNING,
		ERROR,
		FATAL_ERROR
	};

	std::filesystem::path path_absolute = std::filesystem::current_path();
	std::filesystem::path path_logs = path_absolute.append("logs\\");
	std::string namefile = "logs";
	std::string fileformat = ".log";
	std::string state_tipy;
	std::fstream file;

	bool exist_directory()
	{
		if (std::filesystem::is_directory(path_logs))
			return true;
		else
			return false;
	}

	bool openfile(std::filesystem::path path)
	{
		if (!exist_directory())
			std::filesystem::create_directory(path);

		file.open(path.string() + namefile + fileformat, std::ios::in | std::ios::app);
		if (!file.is_open())
			return false;
		else
			return true;

	}

	void logsrecord(std::string str, tipy_debug _tipy_debug)
	{
		switch (_tipy_debug)
		{
		case logsystem::DEBUG:
			state_tipy = "DEBUG:";
			break;
		case logsystem::WARNING:
			state_tipy = "WARNING:";
			break;
		case logsystem::ERROR:
			state_tipy = "ERROR:";
			break;
		case logsystem::FATAL_ERROR:
			state_tipy = "FATAL_ERROR:";
			break;
		default:
			state_tipy = "String:";
			break;
		}

		if (openfile(path_logs))
		{
			std::time_t result = std::time(NULL);
			tm ss;
			localtime_s(&ss, &result);
			file << state_tipy
				<< " "
				<< ss.tm_hour
				<< ':'
				<< ss.tm_min
				<< ':'
				<< ss.tm_sec
				<< ' '
				<< str << "\n";
			file.close();
		}
	}

}

