#include "Shaders/common.h"
#include "Shaders/app_common_impl.h"

#include <algorithm>
#include <string_view>
#include <utility>

constexpr size_t BUF_SIZE = 32;

void On_error(const char *msg)
{
    Env::DocGroup root("");
    {
        Env::DocAddText("error", msg);
    }
}

void ReturnPublicKey()
{
    uint32_t size = Env::DocGetBlob("key_material", nullptr, 0);
    auto p = std::make_unique<uint8_t[]>(size);
    Env::DocGetBlob("key_material", p.get(), size);
    PubKey pubKey;
    Env::DerivePk(pubKey, p.get(), size);
    Env::DocAddBlob_T("pub_key", pubKey);
}

BEAM_EXPORT void Method_0()
{
    Env::DocGroup root("");
    {
        Env::DocGroup gr("roles");
        {
            Env::DocGroup grRole("user");
            {
                Env::DocGroup grMethod("get_public_key");
                Env::DocAddText("key_material", "Blob");
            }
        }
    }
}

BEAM_EXPORT void Method_1()
{
    char buf[BUF_SIZE];

    if (!Env::DocGetText("role", buf, sizeof(buf)))
    {
        return On_error("Role not specified");
    }

    if (std::string_view(buf) != "user")
    {
        return On_error("Invalid role");
    }

    if (!Env::DocGetText("action", buf, sizeof(buf)))
    {
        return On_error("Action not specified");
    }

    if (std::string_view(buf) == "get_public_key")
    {
        ReturnPublicKey();
    }
    else
    {
        On_error("Invalid action");
    }
}
