#ifndef _OPENGL_TEXTURE_TEXTURE_H_
#define _OPENGL_TEXTURE_TEXTURE_H_

#include <Basic/Ptr.h>

#include <vector>
#include <string>

namespace CppUtil {
	namespace Basic {
		class Image;
	}

	namespace OpenGL {
		class Texture {
		public:
			enum ENUM_TYPE
			{
				ENUM_TYPE_NOT_VALID,
				ENUM_TYPE_2D,
				ENUM_TYPE_CUBE_MAP,
				ENUM_TYPE_2D_DYNAMIC,
			};

			Texture();
			Texture(unsigned ID, ENUM_TYPE type);
			Texture(ENUM_TYPE type);
			enum class MAG_FILTER {
				NEAREST,
				LINEAR
			};
			Texture(unsigned width, unsigned height, const float * data, unsigned dataType, unsigned srcFormat, unsigned internalFormat, MAG_FILTER magFilter = MAG_FILTER::NEAREST);
			Texture(const std::vector<std::string> & skybox);
			Texture(const std::vector<Basic::PtrC<Basic::Image>> & skyboxImgs);
			Texture(const std::string & path, bool flip = false, bool gammaCorrection = false);
			Texture(Basic::PtrC<Basic::Image> img);

			bool Load(const std::vector<std::string> & skybox);
			bool Load(const std::string & path, bool flip = false, bool gammaCorrection = false);
			bool SetImg(const Basic::Image & img);
			bool GenBufferForCubemap(unsigned width, unsigned height);
			bool GenMipmap();

			bool Use(unsigned id = 0) const;
			void Bind() const;
			void UnBind() const;

			const unsigned & GetID() const { return ID; }
			ENUM_TYPE GetType() const { return type; }
			bool IsValid() const;

			void Free();

			static const Texture InValid;
		private:
			static unsigned Type2GL(ENUM_TYPE type);
			static std::string Type2Str(ENUM_TYPE type);

			unsigned ID;
			ENUM_TYPE type;
		};
	}
}

#endif // !_OPENGL_TEXTURE_TEXTURE_H_
