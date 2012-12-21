// this program is automatically generated by jenerator. do not edit.
#include "../framework/keeper.hpp"
#include "../framework/aggregators.hpp"
#include "../common/exception.hpp"
#include "classifier_types.hpp"
#include <glog/logging.h>
using namespace jubatus;
using namespace jubatus::framework;
int main(int args, char** argv){
  try{
    keeper k(keeper_argv(args,argv,"classifier"));
    k.register_random<std::string >("get_config"); //pass analysis
    k.register_random<int, std::vector<std::pair<std::string,datum > > >("train"); //pass update
    k.register_random<std::vector<std::vector<estimate_result > >, std::vector<datum > >("classify"); //pass analysis
    k.register_broadcast<bool, std::string >("save", pfi::lang::function<bool(bool,bool)>(&all_and)); //update
    k.register_broadcast<bool, std::string >("load", pfi::lang::function<bool(bool,bool)>(&all_and)); //update
    k.register_broadcast<std::map<std::string,std::map<std::string,std::string > > >("get_status", pfi::lang::function<std::map<std::string,std::map<std::string,std::string > >(std::map<std::string,std::map<std::string,std::string > >,std::map<std::string,std::map<std::string,std::string > >)>(&merge<std::string,std::map<std::string,std::string > >)); //analysis
    return k.run();
  } catch (const jubatus::exception::jubatus_exception& e) {
    LOG(FATAL) << e.diagnostic_information(true);
    return -1;
  }
}
