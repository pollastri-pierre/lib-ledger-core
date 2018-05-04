// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#include "NJSBitcoinLikeAddressCpp.hpp"

using namespace v8;
using namespace node;
using namespace std;

NAN_METHOD(NJSBitcoinLikeAddress::getVersion) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::getVersion needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSBitcoinLikeAddress* obj = Nan::ObjectWrap::Unwrap<NJSBitcoinLikeAddress>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::getVersion : implementation of BitcoinLikeAddress is not valid");
    }

    auto result = cpp_impl->getVersion();

    //Wrap result in node object
    Local<Array> arg_0 = Nan::New<Array>();
    for(size_t arg_0_id = 0; arg_0_id < result.size(); arg_0_id++)
    {
        auto arg_0_elem = Nan::New<Uint32>(result[arg_0_id]);
        arg_0->Set((int)arg_0_id,arg_0_elem);
    }


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSBitcoinLikeAddress::getHash160) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::getHash160 needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSBitcoinLikeAddress* obj = Nan::ObjectWrap::Unwrap<NJSBitcoinLikeAddress>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::getHash160 : implementation of BitcoinLikeAddress is not valid");
    }

    auto result = cpp_impl->getHash160();

    //Wrap result in node object
    Local<Array> arg_0 = Nan::New<Array>();
    for(size_t arg_0_id = 0; arg_0_id < result.size(); arg_0_id++)
    {
        auto arg_0_elem = Nan::New<Uint32>(result[arg_0_id]);
        arg_0->Set((int)arg_0_id,arg_0_elem);
    }


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSBitcoinLikeAddress::getNetworkParameters) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::getNetworkParameters needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSBitcoinLikeAddress* obj = Nan::ObjectWrap::Unwrap<NJSBitcoinLikeAddress>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::getNetworkParameters : implementation of BitcoinLikeAddress is not valid");
    }

    auto result = cpp_impl->getNetworkParameters();

    //Wrap result in node object
    auto arg_0 = Nan::New<Object>();
    auto arg_0_1 = Nan::New<String>(result.Identifier).ToLocalChecked();
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("Identifier").ToLocalChecked(), arg_0_1);
    Local<Array> arg_0_2 = Nan::New<Array>();
    for(size_t arg_0_2_id = 0; arg_0_2_id < result.P2PKHVersion.size(); arg_0_2_id++)
    {
        auto arg_0_2_elem = Nan::New<Uint32>(result.P2PKHVersion[arg_0_2_id]);
        arg_0_2->Set((int)arg_0_2_id,arg_0_2_elem);
    }

    Nan::DefineOwnProperty(arg_0, Nan::New<String>("P2PKHVersion").ToLocalChecked(), arg_0_2);
    Local<Array> arg_0_3 = Nan::New<Array>();
    for(size_t arg_0_3_id = 0; arg_0_3_id < result.P2SHVersion.size(); arg_0_3_id++)
    {
        auto arg_0_3_elem = Nan::New<Uint32>(result.P2SHVersion[arg_0_3_id]);
        arg_0_3->Set((int)arg_0_3_id,arg_0_3_elem);
    }

    Nan::DefineOwnProperty(arg_0, Nan::New<String>("P2SHVersion").ToLocalChecked(), arg_0_3);
    Local<Array> arg_0_4 = Nan::New<Array>();
    for(size_t arg_0_4_id = 0; arg_0_4_id < result.XPUBVersion.size(); arg_0_4_id++)
    {
        auto arg_0_4_elem = Nan::New<Uint32>(result.XPUBVersion[arg_0_4_id]);
        arg_0_4->Set((int)arg_0_4_id,arg_0_4_elem);
    }

    Nan::DefineOwnProperty(arg_0, Nan::New<String>("XPUBVersion").ToLocalChecked(), arg_0_4);
    auto arg_0_5 = Nan::New<Integer>((int)result.FeePolicy);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("FeePolicy").ToLocalChecked(), arg_0_5);
    auto arg_0_6 = Nan::New<Number>(result.DustAmount);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("DustAmount").ToLocalChecked(), arg_0_6);
    auto arg_0_7 = Nan::New<String>(result.MessagePrefix).ToLocalChecked();
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("MessagePrefix").ToLocalChecked(), arg_0_7);
    auto arg_0_8 = Nan::New<Boolean>(result.UsesTimestampedTransaction);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("UsesTimestampedTransaction").ToLocalChecked(), arg_0_8);
    Local<Array> arg_0_9 = Nan::New<Array>();
    for(size_t arg_0_9_id = 0; arg_0_9_id < result.SigHash.size(); arg_0_9_id++)
    {
        auto arg_0_9_elem = Nan::New<Uint32>(result.SigHash[arg_0_9_id]);
        arg_0_9->Set((int)arg_0_9_id,arg_0_9_elem);
    }

    Nan::DefineOwnProperty(arg_0, Nan::New<String>("SigHash").ToLocalChecked(), arg_0_9);


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSBitcoinLikeAddress::toBase58) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::toBase58 needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSBitcoinLikeAddress* obj = Nan::ObjectWrap::Unwrap<NJSBitcoinLikeAddress>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::toBase58 : implementation of BitcoinLikeAddress is not valid");
    }

    auto result = cpp_impl->toBase58();

    //Wrap result in node object
    auto arg_0 = Nan::New<String>(result).ToLocalChecked();

    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSBitcoinLikeAddress::isP2SH) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::isP2SH needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSBitcoinLikeAddress* obj = Nan::ObjectWrap::Unwrap<NJSBitcoinLikeAddress>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::isP2SH : implementation of BitcoinLikeAddress is not valid");
    }

    auto result = cpp_impl->isP2SH();

    //Wrap result in node object
    auto arg_0 = Nan::New<Boolean>(result);

    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSBitcoinLikeAddress::isP2PKH) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::isP2PKH needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSBitcoinLikeAddress* obj = Nan::ObjectWrap::Unwrap<NJSBitcoinLikeAddress>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::isP2PKH : implementation of BitcoinLikeAddress is not valid");
    }

    auto result = cpp_impl->isP2PKH();

    //Wrap result in node object
    auto arg_0 = Nan::New<Boolean>(result);

    //Return result
    info.GetReturnValue().Set(arg_0);
}

NAN_METHOD(NJSBitcoinLikeAddress::getDerivationPath) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::getDerivationPath needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSBitcoinLikeAddress* obj = Nan::ObjectWrap::Unwrap<NJSBitcoinLikeAddress>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::getDerivationPath : implementation of BitcoinLikeAddress is not valid");
    }

    auto result = cpp_impl->getDerivationPath();

    //Wrap result in node object
    Local<Value> arg_0;
    if(result)
    {
        auto arg_0_optional = (result).value();
        auto arg_0_tmp = Nan::New<String>(arg_0_optional).ToLocalChecked();
        arg_0 = arg_0_tmp;
    }


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSBitcoinLikeAddress::fromBase58) {

    //Check if method called with right number of arguments
    if(info.Length() != 2)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::fromBase58 needs 2 arguments");
    }

    //Check if parameters have correct types

    auto field_arg_0_1 = Nan::Get(info[0]->ToObject(), Nan::New<String>("Identifier").ToLocalChecked()).ToLocalChecked();
    String::Utf8Value string_arg_0_1(field_arg_0_1->ToString());
    auto arg_0_1 = std::string(*string_arg_0_1);

    auto field_arg_0_2 = Nan::Get(info[0]->ToObject(), Nan::New<String>("P2PKHVersion").ToLocalChecked()).ToLocalChecked();
    vector<uint8_t> arg_0_2;
    Local<Array> arg_0_2_container = Local<Array>::Cast(field_arg_0_2);
    for(uint32_t arg_0_2_id = 0; arg_0_2_id < arg_0_2_container->Length(); arg_0_2_id++)
    {
        if(arg_0_2_container->Get(arg_0_2_id)->IsUint32())
        {
            auto arg_0_2_elem = Nan::To<uint32_t>(arg_0_2_container->Get(arg_0_2_id)).FromJust();
            arg_0_2.emplace_back(arg_0_2_elem);
        }
    }


    auto field_arg_0_3 = Nan::Get(info[0]->ToObject(), Nan::New<String>("P2SHVersion").ToLocalChecked()).ToLocalChecked();
    vector<uint8_t> arg_0_3;
    Local<Array> arg_0_3_container = Local<Array>::Cast(field_arg_0_3);
    for(uint32_t arg_0_3_id = 0; arg_0_3_id < arg_0_3_container->Length(); arg_0_3_id++)
    {
        if(arg_0_3_container->Get(arg_0_3_id)->IsUint32())
        {
            auto arg_0_3_elem = Nan::To<uint32_t>(arg_0_3_container->Get(arg_0_3_id)).FromJust();
            arg_0_3.emplace_back(arg_0_3_elem);
        }
    }


    auto field_arg_0_4 = Nan::Get(info[0]->ToObject(), Nan::New<String>("XPUBVersion").ToLocalChecked()).ToLocalChecked();
    vector<uint8_t> arg_0_4;
    Local<Array> arg_0_4_container = Local<Array>::Cast(field_arg_0_4);
    for(uint32_t arg_0_4_id = 0; arg_0_4_id < arg_0_4_container->Length(); arg_0_4_id++)
    {
        if(arg_0_4_container->Get(arg_0_4_id)->IsUint32())
        {
            auto arg_0_4_elem = Nan::To<uint32_t>(arg_0_4_container->Get(arg_0_4_id)).FromJust();
            arg_0_4.emplace_back(arg_0_4_elem);
        }
    }


    auto field_arg_0_5 = Nan::Get(info[0]->ToObject(), Nan::New<String>("FeePolicy").ToLocalChecked()).ToLocalChecked();
    auto arg_0_5 = (ledger::core::api::BitcoinLikeFeePolicy)Nan::To<int>(field_arg_0_5).FromJust();

    auto field_arg_0_6 = Nan::Get(info[0]->ToObject(), Nan::New<String>("DustAmount").ToLocalChecked()).ToLocalChecked();
    auto arg_0_6 = Nan::To<int64_t>(field_arg_0_6).FromJust();

    auto field_arg_0_7 = Nan::Get(info[0]->ToObject(), Nan::New<String>("MessagePrefix").ToLocalChecked()).ToLocalChecked();
    String::Utf8Value string_arg_0_7(field_arg_0_7->ToString());
    auto arg_0_7 = std::string(*string_arg_0_7);

    auto field_arg_0_8 = Nan::Get(info[0]->ToObject(), Nan::New<String>("UsesTimestampedTransaction").ToLocalChecked()).ToLocalChecked();
    auto arg_0_8 = Nan::To<bool>(field_arg_0_8).FromJust();

    auto field_arg_0_9 = Nan::Get(info[0]->ToObject(), Nan::New<String>("SigHash").ToLocalChecked()).ToLocalChecked();
    vector<uint8_t> arg_0_9;
    Local<Array> arg_0_9_container = Local<Array>::Cast(field_arg_0_9);
    for(uint32_t arg_0_9_id = 0; arg_0_9_id < arg_0_9_container->Length(); arg_0_9_id++)
    {
        if(arg_0_9_container->Get(arg_0_9_id)->IsUint32())
        {
            auto arg_0_9_elem = Nan::To<uint32_t>(arg_0_9_container->Get(arg_0_9_id)).FromJust();
            arg_0_9.emplace_back(arg_0_9_elem);
        }
    }

    BitcoinLikeNetworkParameters arg_0(arg_0_1, arg_0_2, arg_0_3, arg_0_4, arg_0_5, arg_0_6, arg_0_7, arg_0_8, arg_0_9);

    String::Utf8Value string_arg_1(info[1]->ToString());
    auto arg_1 = std::string(*string_arg_1);

    auto result = BitcoinLikeAddress::fromBase58(arg_0,arg_1);

    //Wrap result in node object
    auto arg_2_wrap = NJSBitcoinLikeAddress::wrap(result);
    auto arg_2 = Nan::ObjectWrap::Unwrap<NJSBitcoinLikeAddress>(arg_2_wrap)->handle();


    //Return result
    info.GetReturnValue().Set(arg_2);
}

NAN_METHOD(NJSBitcoinLikeAddress::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress function can only be called as constructor (use New)");
    }

    //Check if NJSBitcoinLikeAddress::New called with right number of arguments
    if(info.Length() != 2)
    {
        return Nan::ThrowError("NJSBitcoinLikeAddress::New needs same number of arguments as ledger::core::api::BitcoinLikeAddress::fromBase58 method");
    }

    //Unwrap objects to get C++ classes

    auto field_arg_0_1 = Nan::Get(info[0]->ToObject(), Nan::New<String>("Identifier").ToLocalChecked()).ToLocalChecked();
    String::Utf8Value string_arg_0_1(field_arg_0_1->ToString());
    auto arg_0_1 = std::string(*string_arg_0_1);

    auto field_arg_0_2 = Nan::Get(info[0]->ToObject(), Nan::New<String>("P2PKHVersion").ToLocalChecked()).ToLocalChecked();
    vector<uint8_t> arg_0_2;
    Local<Array> arg_0_2_container = Local<Array>::Cast(field_arg_0_2);
    for(uint32_t arg_0_2_id = 0; arg_0_2_id < arg_0_2_container->Length(); arg_0_2_id++)
    {
        if(arg_0_2_container->Get(arg_0_2_id)->IsUint32())
        {
            auto arg_0_2_elem = Nan::To<uint32_t>(arg_0_2_container->Get(arg_0_2_id)).FromJust();
            arg_0_2.emplace_back(arg_0_2_elem);
        }
    }


    auto field_arg_0_3 = Nan::Get(info[0]->ToObject(), Nan::New<String>("P2SHVersion").ToLocalChecked()).ToLocalChecked();
    vector<uint8_t> arg_0_3;
    Local<Array> arg_0_3_container = Local<Array>::Cast(field_arg_0_3);
    for(uint32_t arg_0_3_id = 0; arg_0_3_id < arg_0_3_container->Length(); arg_0_3_id++)
    {
        if(arg_0_3_container->Get(arg_0_3_id)->IsUint32())
        {
            auto arg_0_3_elem = Nan::To<uint32_t>(arg_0_3_container->Get(arg_0_3_id)).FromJust();
            arg_0_3.emplace_back(arg_0_3_elem);
        }
    }


    auto field_arg_0_4 = Nan::Get(info[0]->ToObject(), Nan::New<String>("XPUBVersion").ToLocalChecked()).ToLocalChecked();
    vector<uint8_t> arg_0_4;
    Local<Array> arg_0_4_container = Local<Array>::Cast(field_arg_0_4);
    for(uint32_t arg_0_4_id = 0; arg_0_4_id < arg_0_4_container->Length(); arg_0_4_id++)
    {
        if(arg_0_4_container->Get(arg_0_4_id)->IsUint32())
        {
            auto arg_0_4_elem = Nan::To<uint32_t>(arg_0_4_container->Get(arg_0_4_id)).FromJust();
            arg_0_4.emplace_back(arg_0_4_elem);
        }
    }


    auto field_arg_0_5 = Nan::Get(info[0]->ToObject(), Nan::New<String>("FeePolicy").ToLocalChecked()).ToLocalChecked();
    auto arg_0_5 = (ledger::core::api::BitcoinLikeFeePolicy)Nan::To<int>(field_arg_0_5).FromJust();

    auto field_arg_0_6 = Nan::Get(info[0]->ToObject(), Nan::New<String>("DustAmount").ToLocalChecked()).ToLocalChecked();
    auto arg_0_6 = Nan::To<int64_t>(field_arg_0_6).FromJust();

    auto field_arg_0_7 = Nan::Get(info[0]->ToObject(), Nan::New<String>("MessagePrefix").ToLocalChecked()).ToLocalChecked();
    String::Utf8Value string_arg_0_7(field_arg_0_7->ToString());
    auto arg_0_7 = std::string(*string_arg_0_7);

    auto field_arg_0_8 = Nan::Get(info[0]->ToObject(), Nan::New<String>("UsesTimestampedTransaction").ToLocalChecked()).ToLocalChecked();
    auto arg_0_8 = Nan::To<bool>(field_arg_0_8).FromJust();

    auto field_arg_0_9 = Nan::Get(info[0]->ToObject(), Nan::New<String>("SigHash").ToLocalChecked()).ToLocalChecked();
    vector<uint8_t> arg_0_9;
    Local<Array> arg_0_9_container = Local<Array>::Cast(field_arg_0_9);
    for(uint32_t arg_0_9_id = 0; arg_0_9_id < arg_0_9_container->Length(); arg_0_9_id++)
    {
        if(arg_0_9_container->Get(arg_0_9_id)->IsUint32())
        {
            auto arg_0_9_elem = Nan::To<uint32_t>(arg_0_9_container->Get(arg_0_9_id)).FromJust();
            arg_0_9.emplace_back(arg_0_9_elem);
        }
    }

    BitcoinLikeNetworkParameters arg_0(arg_0_1, arg_0_2, arg_0_3, arg_0_4, arg_0_5, arg_0_6, arg_0_7, arg_0_8, arg_0_9);

    String::Utf8Value string_arg_1(info[1]->ToString());
    auto arg_1 = std::string(*string_arg_1);

    //Call factory
    auto cpp_instance = ledger::core::api::BitcoinLikeAddress::fromBase58(arg_0,arg_1);
    NJSBitcoinLikeAddress *node_instance = new NJSBitcoinLikeAddress(cpp_instance);

    if(node_instance)
    {
        //Wrap and return node instance
        node_instance->Wrap(info.This());
        node_instance->Ref();
        info.GetReturnValue().Set(info.This());
    }
}


Nan::Persistent<ObjectTemplate> NJSBitcoinLikeAddress::BitcoinLikeAddress_prototype;

Handle<Object> NJSBitcoinLikeAddress::wrap(const std::shared_ptr<ledger::core::api::BitcoinLikeAddress> &object) {
    Nan::HandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(BitcoinLikeAddress_prototype);

    Handle<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance();
        NJSBitcoinLikeAddress *new_obj = new NJSBitcoinLikeAddress(object);
        if(new_obj)
        {
            new_obj->Wrap(obj);
            new_obj->Ref();
        }
    }
    else
    {
        Nan::ThrowError("NJSBitcoinLikeAddress::wrap: object template not valid");
    }
    return obj;
}

NAN_METHOD(NJSBitcoinLikeAddress::isNull) {
    NJSBitcoinLikeAddress* obj = Nan::ObjectWrap::Unwrap<NJSBitcoinLikeAddress>(info.This());
    auto cpp_implementation = obj->getCppImpl();
    auto isNull = !cpp_implementation ? true : false;
    return info.GetReturnValue().Set(Nan::New<Boolean>(isNull));
}

void NJSBitcoinLikeAddress::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSBitcoinLikeAddress::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSBitcoinLikeAddress").ToLocalChecked());

    //SetPrototypeMethod all methods
    Nan::SetPrototypeMethod(func_template,"getVersion", getVersion);
    Nan::SetPrototypeMethod(func_template,"getHash160", getHash160);
    Nan::SetPrototypeMethod(func_template,"getNetworkParameters", getNetworkParameters);
    Nan::SetPrototypeMethod(func_template,"toBase58", toBase58);
    Nan::SetPrototypeMethod(func_template,"isP2SH", isP2SH);
    Nan::SetPrototypeMethod(func_template,"isP2PKH", isP2PKH);
    //Set object prototype
    BitcoinLikeAddress_prototype.Reset(objectTemplate);
    Nan::SetPrototypeMethod(func_template,"isNull", isNull);

    //Add template to target
    target->Set(Nan::New<String>("NJSBitcoinLikeAddress").ToLocalChecked(), func_template->GetFunction());
}
