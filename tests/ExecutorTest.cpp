//
// Created by cuihang on 2024/12/3.
//
#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"
namespace adas
{

                bool operator==(const Pose& lhs, const Pose& rhs)
                {
                    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
                }

                TEST(ExecutorTest, should_return_init_pose_when_without_command)
                {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor(Pose{0, 0, Heading::East}));

                    const Pose target({0, 0, Heading::East});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
                {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor());
                    const Pose target({0, 0, Heading::North});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest,should_return_x_plus_1_given_command_is_M_and_facing_is_E)

                {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor(Pose{0, 0, Heading::East}));
                    executor->Execute("M");
                    const Pose target({1, 0, Heading::East});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest,should_return_x_minus_1_given_command_is_M_and_facing_is_W)
                {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor(Pose{0, 0, Heading::West}));
                    executor->Execute("M");
                    const Pose target({-1, 0, Heading::West});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest,should_return_y_plus_1_given_command_is_M_and_facing_is_N)
                {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor(Pose{0, 0, Heading::North}));
                    executor->Execute("M");
                    const Pose target({0, 1, Heading::North});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest,should_return_y_minus_1_given_command_is_M_and_facing_is_S)
                {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor(Pose{0, 0, Heading::South}));
                    executor->Execute("M");
                    const Pose target({0, -1, Heading::South});
                    ASSERT_EQ(target,executor->Query());
                }

                TEST(ExecutorTest, should_return_west_when_command_is_L_and_facing_is_north) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::North}));
                    executor->Execute("L");
                    const Pose target({0, 0, Heading::West});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_return_east_when_command_is_R_and_facing_is_north) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::North}));
                    executor->Execute("R");
                    const Pose target({0, 0, Heading::East});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_return_north_when_command_is_L_and_facing_is_east) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::East}));
                    executor->Execute("L");
                    const Pose target({0, 0, Heading::North});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_return_south_when_command_is_R_and_facing_is_east) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::East}));
                    executor->Execute("R");
                    const Pose target({0, 0, Heading::South});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_return_east_when_command_is_L_and_facing_is_south) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::South}));
                    executor->Execute("L");
                    const Pose target({0, 0, Heading::East});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_return_west_when_command_is_R_and_facing_is_south) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::South}));
                    executor->Execute("R");
                    const Pose target({0, 0, Heading::West});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_return_south_when_command_is_L_and_facing_is_west) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::West}));
                    executor->Execute("L");
                    const Pose target({0, 0, Heading::South});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_return_north_when_command_is_R_and_facing_is_west) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::West}));
                    executor->Execute("R");
                    const Pose target({0, 0, Heading::North});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_handle_multiple_turns_LRL) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::North}));
                    executor->Execute("LRL");
                    const Pose target({0, 0, Heading::West});
                    ASSERT_EQ(target, executor->Query());
                }

                TEST(ExecutorTest, should_handle_multiple_turns_RLRL) {
                    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, Heading::North}));
                    executor->Execute("RLRL");
                    const Pose target({0, 0, Heading::North});
                    ASSERT_EQ(target, executor->Query());
                }






}