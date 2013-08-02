LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hellolua_shared

LOCAL_MODULE_FILENAME := libhellolua

LOCAL_SRC_FILES := hellolua/main.cpp \
                   ../../Classes/AppDelegate.cpp \
		   ../../Classes/ClipLayer.cpp   \
		   ../../Classes/StyleLabel.cpp   \
		   ../../Classes/BYGraySprite.cpp   \
		   ../../Classes/network/CCHTTPRequest.cpp   \
		   ../../Classes/network/CCNetwork.cpp   \
		   ../../Classes/cocos2dx_support/cocos2dx_cliplayer_luabinding.cpp   \
		   ../../Classes/cocos2dx_support/cocos2dx_network_luabinding.cpp   \
		   ../../Classes/cocos2dx_support/cocos2dx_stylelabel_luabinding.cpp   \
		   ../../Classes/cocos2dx_support/cocos2dx_extensions_luabinding.cpp   \
		   ../../Classes/cocos2dx_support/cocos2dx_BYGraySprite_luabinding.cpp   \
		   ../../Classes/cocos2dx_support/luaj/LuaJavaBridge.cpp   \
		   ../../Classes/cocos2dx_support/luaj/com_qeeplay_frameworks_LuaJavaBridge.cpp   \


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
		    $(LOCAL_PATH)/../../Classes/cocos2dx_support \
		    $(LOCAL_PATH)/../../Classes/cocos2dx_support/luaj \
		    $(LOCAL_PATH)/../../Classes/network \
			
LOCAL_STATIC_LIBRARIES := curl_static_prebuilt

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_lua_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, /cygdrive/d/GitHub/cocos2d-x)
$(call import-add-path, /cygdrive/d/GitHub/cocos2d-x/scripting)
$(call import-add-path, /cygdrive/d/GitHub/cocos2d-x/cocos2dx/platform/third_party/android/prebuilt)


$(call import-module,cocos2dx)
$(call import-module,CocosDenshion/android)
$(call import-module,scripting/lua/proj.android)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,extensions)
