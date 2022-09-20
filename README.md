# USAGE

`beam-wallet<NETWORK SUFFIX> shader --shader_app_file=get_pub_key_app.wasm --shader_args="role=user,action=get_public_key,key_material=<key material in hex>" -n <node url for some reason>`

or

pass `role=user,action=get_public_key,key_material=<key material in hex>` and wasm file to the wallet API [invoke_contract](https://github.com/BeamMW/beam/wiki/Beam-wallet-protocol-API-v7.1#invoke_contract)`
