#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForest {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[5] = { 0 };
                        // tree #1
                        if (x[3] <= -0.22238226979970932) {
                            if (x[0] <= 0.14451148733496666) {
                                votes[2] += 1;
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        else {
                            if (x[2] <= 1.122367024421692) {
                                votes[1] += 1;
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        // tree #2
                        if (x[1] <= 0.183273047208786) {
                            if (x[2] <= -0.9470191895961761) {
                                votes[4] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[8] <= -0.9023929238319397) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[6] <= 0.10036541894078255) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        // tree #3
                        if (x[8] <= 0.12037400156259537) {
                            if (x[9] <= 0.3013916686177254) {
                                if (x[2] <= 0.9732822775840759) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[2] <= -0.8179606795310974) {
                                votes[0] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        // tree #4
                        if (x[3] <= 0.9575687646865845) {
                            if (x[2] <= -1.0026478171348572) {
                                votes[4] += 1;
                            }

                            else {
                                if (x[3] <= -0.12217411398887634) {
                                    if (x[4] <= 0.5848596394062042) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #5
                        if (x[4] <= -1.4474098682403564) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[1] <= -0.7750326693058014) {
                                votes[4] += 1;
                            }

                            else {
                                if (x[1] <= 0.19754061102867126) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[9] <= 0.008024963084608316) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #6
                        if (x[2] <= 0.10324996709823608) {
                            if (x[8] <= -0.0450439217092935) {
                                votes[4] += 1;
                            }

                            else {
                                if (x[0] <= -0.2835700288414955) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[3] <= 1.1905527114868164) {
                                votes[3] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #7
                        if (x[1] <= 0.19516269862651825) {
                            if (x[10] <= -0.416891410946846) {
                                votes[4] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[0] <= -1.240458071231842) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[0] <= -0.2122231051325798) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        // tree #8
                        if (x[3] <= -1.03156316280365) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[0] <= 0.7278774231672287) {
                                if (x[5] <= 0.22757836431264877) {
                                    if (x[2] <= 1.0622881054878235) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        // tree #9
                        if (x[0] <= 0.19067712873220444) {
                            if (x[3] <= 1.0552717447280884) {
                                if (x[1] <= 0.9275650978088379) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[6] <= 0.08932336419820786) {
                                votes[0] += 1;
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        // tree #10
                        if (x[0] <= 0.20326776802539825) {
                            if (x[3] <= 0.9901364147663116) {
                                if (x[2] <= 0.20115643739700317) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[8] <= -0.18221976608037949) {
                                votes[4] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #11
                        if (x[3] <= -0.8812509179115295) {
                            if (x[2] <= -1.0271244049072266) {
                                votes[4] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[2] <= 0.14552775025367737) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[9] <= 0.044860243797302246) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #12
                        if (x[2] <= 0.1766798198223114) {
                            if (x[3] <= -0.851188451051712) {
                                if (x[5] <= 0.07944214716553688) {
                                    votes[4] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[9] <= 0.026442603208124638) {
                                votes[3] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #13
                        if (x[2] <= 0.1366271674633026) {
                            if (x[0] <= 0.21585839614272118) {
                                votes[2] += 1;
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        else {
                            if (x[9] <= 0.3119160234928131) {
                                if (x[9] <= -0.33007028698921204) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #14
                        if (x[3] <= -0.02196595072746277) {
                            if (x[3] <= -0.8536936640739441) {
                                if (x[9] <= 0.18167699873447418) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[10] <= -0.4470714181661606) {
                                votes[3] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #15
                        if (x[1] <= 0.1214468777179718) {
                            if (x[1] <= -0.7464975118637085) {
                                if (x[8] <= 0.5177804827690125) {
                                    votes[4] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[3] <= 0.9976520240306854) {
                                votes[3] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #16
                        if (x[2] <= 0.19225585460662842) {
                            if (x[1] <= -0.7916781604290009) {
                                if (x[1] <= -1.1364780068397522) {
                                    votes[4] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[3] <= 1.1529747247695923) {
                                votes[3] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #17
                        if (x[2] <= 0.1388522982597351) {
                            if (x[0] <= 0.31238657236099243) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[10] <= -0.5625879913568497) {
                                    votes[4] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[2] <= 1.1090161800384521) {
                                if (x[4] <= 0.6070904731750488) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        // tree #18
                        if (x[9] <= 0.1408950835466385) {
                            if (x[3] <= -0.03699716925621033) {
                                votes[0] += 1;
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        else {
                            if (x[1] <= 0.19516268372535706) {
                                if (x[7] <= -0.23597876727581024) {
                                    votes[4] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #19
                        if (x[3] <= 0.05569538474082947) {
                            if (x[1] <= -0.8130795359611511) {
                                votes[0] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[8] <= -0.9548425376415253) {
                                votes[1] += 1;
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        // tree #20
                        if (x[1] <= 0.8443375527858734) {
                            if (x[0] <= 0.20326775941066444) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[0] <= 1.3951809406280518) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }
                        }

                        else {
                            if (x[3] <= 1.1730163097381592) {
                                votes[3] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #21
                        if (x[1] <= 0.2141861468553543) {
                            if (x[1] <= -0.8130795359611511) {
                                if (x[3] <= -0.9914798736572266) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[4] <= 0.6719304323196411) {
                                votes[3] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #22
                        if (x[3] <= -0.9213341772556305) {
                            if (x[7] <= -0.1475198119878769) {
                                if (x[3] <= -0.976448655128479) {
                                    votes[4] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[3] <= 0.05569535493850708) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[1] <= 1.022682249546051) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        // tree #23
                        if (x[1] <= 0.19516271352767944) {
                            if (x[1] <= -0.8202133476734161) {
                                votes[0] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[4] <= -0.22841870784759521) {
                                votes[3] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #24
                        if (x[4] <= -0.30066895484924316) {
                            if (x[2] <= 0.07432305812835693) {
                                votes[0] += 1;
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        else {
                            if (x[1] <= 0.116690993309021) {
                                votes[4] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #25
                        if (x[4] <= -0.269175261259079) {
                            if (x[8] <= -0.14389121904969215) {
                                votes[3] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[1] <= -0.7916781604290009) {
                                votes[4] += 1;
                            }

                            else {
                                if (x[3] <= -0.5831316411495209) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #26
                        if (x[1] <= 0.19754064083099365) {
                            if (x[3] <= -0.823631227016449) {
                                if (x[0] <= 1.336424708366394) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[8] <= -0.5513841807842255) {
                                votes[1] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #27
                        if (x[1] <= -0.7417416572570801) {
                            if (x[3] <= -0.9964902698993683) {
                                votes[0] += 1;
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        else {
                            if (x[0] <= -1.1649142503738403) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[1] <= 0.2450992316007614) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        // tree #28
                        if (x[3] <= 0.11832547187805176) {
                            if (x[4] <= 0.6663727462291718) {
                                votes[0] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[9] <= -0.08800987340509892) {
                                votes[3] += 1;
                            }

                            else {
                                if (x[0] <= -0.8123765736818314) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #29
                        if (x[0] <= 0.673318013548851) {
                            if (x[3] <= 1.057776927947998) {
                                if (x[4] <= -0.18766215443611145) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[4] <= 0.4811157137155533) {
                                votes[0] += 1;
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        // tree #30
                        if (x[0] <= 0.303992822766304) {
                            if (x[9] <= -0.07616996392607689) {
                                votes[3] += 1;
                            }

                            else {
                                if (x[8] <= -0.7067156434059143) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[8] <= -0.24879039824008942) {
                                votes[4] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 5; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }
                    const char* idxToLabel(uint8_t classIdx) {
    switch (classIdx) {
        case 0:
            return "A";
        case 1:
            return "B";
        case 2:
            return "J";
        case 3:
            return "W";
        case 4:
            return "Y";
        default:
            return "Unknown"; 
        
    }
}


                protected:
                };
            }
        }
    }
