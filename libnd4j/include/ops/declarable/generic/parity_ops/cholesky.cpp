/*******************************************************************************
 * Copyright (c) 2015-2018 Skymind, Inc.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License, Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

//
// Created by GS <sgazeos@gmail.com> at 11/12/2018
//

#include <op_boilerplate.h>
#if NOT_EXCLUDED(OP_cholesky)

#include <ops/declarable/CustomOperations.h>
#include <ops/declarable/helpers/lup.h>
namespace nd4j {
    namespace ops {
        OP_IMPL(cholesky, 1, 1, true) {
            NDArray* input = INPUT_VARIABLE(0);
            NDArray* output = OUTPUT_VARIABLE(0);

            REQUIRE_TRUE(input->rankOf() >=2, 0, "cholesky: The rank of input array should not less than 2, but %i is given", input->rankOf());
            REQUIRE_TRUE(input->sizeAt(-1) == input->sizeAt(-2), 0, "cholesky: The last two dimmensions should be equal, but %i and %i are given", input->sizeAt(-1), input->sizeAt(-2));

            return helpers::cholesky(input, output);
        }
        DECLARE_TYPES(cholesky) {
            getOpDescriptor()
                    ->setAllowedInputTypes(nd4j::DataType::ANY)
                    ->setAllowedOutputTypes({ALL_FLOATS});
        }

    }
}

#endif