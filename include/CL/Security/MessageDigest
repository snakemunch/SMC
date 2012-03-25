
#ifndef CL_SECURITY_MESSAGE_DIGEST_H
#define CL_SECURITY_MESSAGE_DIGEST_H

#include <vector>

namespace CL {

	/**
	  * This <code>MessageDigest</code> class provides applications functionality of a message 
	  * digest algorithm, such as MD5 or SHA.
	  */
	class MessageDigest {
		
	public:
		
		virtual ~MessageDigest() {}
		
		/**
		 * Generates a <code>MessageDigtes</code> object that implements the specified digest algorithm.
		 * If the algorithm is not vailable, NULL pointer will be returned.
		 * 
		 * @param algorithm the name of the algorithm requested.
		 * @return a MessageDigest object implementing the specified algorithm
		 */
		static MessageDigest * obtain(const char *algorithm);
		
		/**
		 * Updates the digest using the specified array of bytes, starting at the specified offset.
		 *
		 * @param input the array of bytes
		 * @param offset the offset to start from in the array of bytes
		 * @param length the number of bytes to use
		 */
		virtual void update(const unsigned char *input, int offset, int length) = 0;
		
		/**
		 * Completes the hash computation by performing final operations such as padding. The digest is reset after this call is made.
		 *
		 * @param result the array of bytes for resulting hash value.
		 */
		virtual void digest(std::vector<unsigned char> &result) = 0;
		
	protected:
		
		MessageDigest();

	};

}

using CL::MessageDigest;

#endif CL_SECURITY_MESSAGE_DIGEST_H
