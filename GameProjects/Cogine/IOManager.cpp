#include "IOManager.h"

#include <fstream>

namespace Cogine {

	bool IOManager::readFileToBuffer(std::string filePath, 
		std::vector<unsigned char>& buffer) {
		std::ifstream file(filePath, std::ios::binary);
		if (file.fail()) {
			perror(filePath.c_str());
			return false;
		}

		//seek to end of file
		file.seekg(0, std::ios::end);

		//Get the file Size
		int fileSize = file.tellg();
		//Back to Beginning of file
		file.seekg(0, std::ios::beg);

		//reduce the file size by any header bytes that might be present
		fileSize -= file.tellg();

		buffer.resize(fileSize);
		file.read((char*)&(buffer[0]), fileSize);
		file.close();

		return true;
	}

	bool IOManager::readFileToBuffer(std::string filePath,
		std::string& buffer) {
		std::ifstream file(filePath, std::ios::binary);
		if (file.fail()) {
			perror(filePath.c_str());
			return false;
		}

		//seek to end of file
		file.seekg(0, std::ios::end);

		//Get the file Size
		int fileSize = file.tellg();
		//Back to Beginning of file
		file.seekg(0, std::ios::beg);

		//reduce the file size by any header bytes that might be present
		fileSize -= file.tellg();

		buffer.resize(fileSize);
		file.read((char*)&(buffer[0]), fileSize);
		file.close();

		return true;

	}

}