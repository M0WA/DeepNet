/**
 *
 * @file Socket.h
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#pragma once

#include <MemoryContainer.h>

namespace networking {

/**
 * @brief implements generic socket
 */
class Socket {
protected:
	/**
	 * creates uninitialized socket
	 */
	Socket();

	/**
	 * creates socket from existing handle
	 * @param socket socket handle
	 */
	Socket(int socket);

public:
	virtual ~Socket();

public:
	/**
	 * creates socket
	 * @return true if successful, false if error
	 */
	bool Create();

	/**
	 * closes socket
	 * @return true if successful, false if error
	 */
	bool Close();

	/**
	 * reads data from socket and returns upon success or timeout
	 * @param data data buffer to read to
	 * @param maxRead read maximum (0 to read all available data)
	 * @param timeout timeout to wait for data
	 * @return number of bytes received
	 */
	size_t Read(
		tools::MemoryContainer<unsigned char>& data,
		const struct timeval& timeout,
		const size_t& maxRead = 0);

	/**
	 * reads data blocking from socket
	 * @param data data buffer to read to
	 * @param read size of data to read
	 * @return number of bytes received
	 */
	size_t Read(
		tools::MemoryContainer<unsigned char>& data,
		const size_t& read);

	/**
	 * write data to socket
	 * @param data data to write to socket
	 * @param dataSize size of data
	 * @return number of bytes written
	 */
	size_t Write(
		const unsigned char* data,
		const size_t& dataSize);

	/**
	 * returns current socket handle
	 * @return socket handle
	 */
	int GetSocket() const {
		return socket; }

	/**
	 * sets socket into non blocking mode
	 */
	void SetNonBlocking();

	/**
	 * sets socket into blocking mode
	 */
	void SetBlocking();

private:
	/**
	 * called when socket is created ( Create() )
	 * @return true if successful, false if error
	 */
	virtual bool OnCreate()=0;

	/**
	 * called when socket is closed ( Close() )
	 * @return true if successful, false if error
	 */
	virtual bool OnClose()=0;

	/**
	 * called when data should be read from the socket
	 * @param data buffer to write data to
	 * @param maxRead read maximum (0 to read all available data)
	 * @param timeout timeout to wait for data
	 * @return true if successful, false if error
	 */
	virtual size_t OnRead(tools::MemoryContainer<unsigned char>& data, const size_t& maxRead, const struct timeval* timeout)=0;

	/**
	 * called when data should be written to the socket
	 * @param data data to write to socket
	 * @param dataSize size of data
	 * @retur number of bytes written
	 */
	virtual size_t OnWrite(const unsigned char* data, const size_t& dataSize)=0;

protected:
	/**
	 * socket handle
	 */
	int socket;
};

}
