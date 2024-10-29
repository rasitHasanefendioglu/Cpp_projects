#include <gtest/gtest.h>
#include "../include/inputHandler.h"
#include "temporaryJson.hpp"
namespace fs = std::filesystem;
class InputHandlerTest : public ::testing::Test {
protected:
    void SetUp() override {
        ih_test = std::make_unique<InputHandler>(tempFile.getPath());
    }

    void TearDown() override {
    }
    std::unique_ptr<InputHandler> ih_test;
    TemporaryJsonFile tempFile{"{\"key\": \"value\"}"};
};


TEST_F(InputHandlerTest, conf_executer_no_data_type_exception){
    EXPECT_THROW(ih_test->confExecuter(), std::out_of_range);
}
TEST_F(InputHandlerTest, conf_executer_with_valid_data){
    tempFile.updateValue("data_type", "int");
    ih_test = std::make_unique<InputHandler>(tempFile.getPath());
    EXPECT_NO_THROW(ih_test->confExecuter());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}