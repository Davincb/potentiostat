#ifndef PS_VOLTAMMETRY_H
#define PS_VOLTAMMETRY_H
#include "ArduinoJson.h"
#include "ps_constants.h"
#include "ps_return_status.h"
#include "ps_base_test.h"
#include "ps_cyclic_test.h"
#include "ps_sinusoid_test.h"
#include "ps_constant_test.h"
#include "ps_linearsweep_test.h"
#include "ps_multistep_test.h"
#include "Array.h"

namespace ps
{

    class Voltammetry
    {

        public:

            Voltammetry();

            BaseTest *getTest(String name);
            ReturnStatus getTest(JsonObject &jsonMsg, JsonObject &jsonDat, BaseTest* &testPtr);

            ReturnStatus getParam(JsonObject &jsonMsg, JsonObject &jsonDat);
            ReturnStatus setParam(JsonObject &jsonMsg, JsonObject &jsonDat);
            ReturnStatus getTestDoneTime(JsonObject &jsonMsg, JsonObject &jsonDat);

            BaseTest baseTest;
            CyclicTest cyclicTest;
            SinusoidTest sinusoidTest;
            ConstantTest constantTest;
            LinearSweepTest linearSweepTest;
            MultiStepTest<2> chronoampTest;
            MultiStepTest<MultiStepMaxSize> multiStepTest;

            static const String TestKey;

        protected:

            Array<BaseTest*,AvailableTestsMaxSize> availableTests_;

    };

}

#endif
