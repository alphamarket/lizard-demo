#ifndef LINE_TESTER_HPP
#define LINE_TESTER_HPP

#include "lizard/lizard.hpp"
#include "src/line.hpp"

namespace test {

using namespace demo;

class line_tester : public lizard_base_tester {
public:
    void run() {
        // a instance created
        line* line_ = new line(0, "TEST_LINE");
        // for demo: check created instance is a pointer?
        IS_POINTER(line_);
        // at instance's ctor we initialized the line# to 0
        // It should be as passed
        IS_ZERO(line_->getLineNumber());
        // The line's content should be as passed
        IS_EQUAL(line_->getContent(), "TEST_LINE");
        // No source defined, so source should be NULL
        IS_NULL(line_->getSource());
        delete(line_);
        // create a new line
        line_ = new line(-1, "INVALID_TEST_LINE");
        // since the line# is `size_t` so any negative line#
        // will dealt as unsigned.
        NOT_EQUAL(line_->getLineNumber(), (unsigned)-1);
        // test line content
        IS_EQUAL(line_->getContent(), "INVALID_TEST_LINE");
        // no source defined as well
        IS_NULL(line_->getSource());
        delete(line_);
    }
};

}

#endif
