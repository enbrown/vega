#pragma once

#include <istream>
#include <string>
#include <vector>
#include <memory>

#include "vega/vega.h"
#include "vega/tag.h"
#include "vega/vr.h"
#include "vega/logger.h"
#include "vega/dicom/io_state.h"
#include "vega/dicom/data_element.h"
#include "vega/dicom/data_set.h"
#include "vega/dicom/raw_reader.h"

namespace vega {
  namespace manipulators {
    class ValueManipulator;
  }

  namespace dictionary {
    class Page;
  }

  namespace dicom {
    class Reader {
      public:
        class FileDoesNotExistError : public vega::Exception { using vega::Exception::Exception; };
        class ReadingError : public vega::Exception { using vega::Exception::Exception; };

      private:
        Logger m_logger;
        RawReader m_raw_reader;
        bool m_allow_any_explicit_vr;

      public:
        Reader(std::shared_ptr<std::istream> is, bool allow_any_explicit_vr = false);

        RawReader& raw_reader();

        const Endian& dicom_endian() const;
        void set_dicom_endianness(const Endian& dicom_endian);

        bool vr_explicit() const;
        void set_vr_explicit(bool vr_explicit);

        bool swap() const;

        std::shared_ptr<DataElement> read_data_element(std::shared_ptr<DataSet> parent);
        std::shared_ptr<DataSet> read_data_set(std::shared_ptr<DataElement> parent);

        // Returns new DataElement if successfully read in
        // Otherwise, returns nullptr and leaves file pointer in original location
        std::shared_ptr<DataElement> read_data_element(const Tag& tag, std::shared_ptr<DataSet> parent);

        bool eof();
        void rewind();
        std::streampos tell();
        void seek_pos(std::streampos pos);
        void seek_delta(std::streampos delta);

      private:
        static std::shared_ptr<manipulators::ValueManipulator> manipulator_for(const DataElement& element);
    };
  }
}
