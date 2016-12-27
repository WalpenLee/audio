/** @file nim_audio.h
  * @brief NIM 提供的语音录制和播放接口
  * @copyright (c) 2015, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/2/10
  */

#ifndef _NIM_AUDIO_MODULE_SDK_H_
#define _NIM_AUDIO_MODULE_SDK_H_
#include "nim_audio_def.h"
//#include "nim_audio_stdbool.h"

#define NAUDIO_API 	__attribute__((visibility("default")))
#ifdef __cplusplus
extern"C"
{
#endif

/** @fn bool nim_audio_init_module(const char* user_data_parent_path)
  * NIM SDK 初始化语音模块
  * @param[in] user_data_parent_path 缓存目录
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_init_module(const char* user_data_parent_path); //win32


/** @fn bool nim_audio_uninit_module()
  * NIM SDK 卸载语音模块（只有在主程序关闭时才有必要调用此接口）
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_uninit_module(); //win32


/** @fn bool nim_audio_play_audio(const char* file_path, const char* call_id, const char* res_id, int audio_format)
  * NIM SDK 播放,通过回调获取开始播放状态
  * @param[in] file_path 播放文件绝对路径
  * @param[in] call_id 用以定位资源的一级ID，可选
  * @param[in] res_id 用以定位资源的二级ID，可选
  * @param[in] audio_format 播放音频格式，AAC : 0， AMR : 1
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_play_audio(const char* file_path, const char* call_id, const char* res_id, int audio_format,void* user_data);//win32,ios,android

/** @fn bool nim_audio_stop_play_audio()
  * NIM SDK 停止播放,通过回调获取停止播放状态
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_stop_play_audio(); //win32,ios,android.

/** @fn bool nim_audio_reg_start_play_cb(nim_rescode_id_cb cb)
  * NIM SDK 注册播放开始事件回调
  * @param[in] cb 回调函数 见nim_audio_def.h
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_reg_start_play_cb(nim_rescode_id_cb cb);

/** @fn bool nim_audio_reg_stop_play_cb(nim_rescode_id_cb cb)
  * NIM SDK 注册停止播放事件回调
  * @param[in] cb 回调函数 见nim_audio_def.h
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_reg_stop_play_cb(nim_rescode_id_cb cb);


   /** @fn bool nim_audio_reg_stop_play_cb(nim_rescode_id_cb cb)
   * NIM SDK 注册播放结束事件回调
   * @param[in] cb 回调函数 见nim_audio_def.h
   * @return bool true 调用成功，false 调用失败
   */
   NAUDIO_API bool nim_audio_reg_play_end_cb(nim_rescode_id_cb cb);

/** @fn bool nim_audio_reg_start_capture_cb(nim_rescode_cb cb)
  * NIM SDK 注册录制语音回调
  * @param[in] cb 回调函数 见nim_audio_def.h
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_reg_start_capture_cb(nim_rescode_cb cb);

/** @fn bool nim_audio_reg_stop_capture_cb(nim_stop_capture_cb cb)
  * NIM SDK 注册录制语音结束回调
  * @param[in] cb 回调函数 见nim_audio_def.h
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_reg_stop_capture_cb(nim_stop_capture_cb cb);

/** @fn bool nim_audio_reg_cancel_audio_cb(nim_rescode_cb cb)
  * NIM SDK 注册取消录制并删除临时文件事件回调
  * @param[in] cb 回调函数 见nim_audio_def.h
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_reg_cancel_audio_cb(nim_rescode_cb cb);


   NAUDIO_API bool nim_audio_reg_audio_error_cb(nim_rescode_cb);
/** @fn bool nim_audio_start_capture(const char* call_id, const char* res_id, int audio_format = 0, int volume = 180, int loudness = 0, const wchar_t* capture_device = nullptr)
  * NIM SDK 录制语音
  * @param[in] call_id 用以定位资源的一级ID，可选
  * @param[in] res_id 用以定位资源的二级ID，可选
  * @param[in] audio_format 音频格式，AAC : 0， AMR : 1
  * @param[in] volume 音量(0 - 255, 默认180)
  * @param[in] loudness 默认0
  * @param[in] capture_device 录音设备
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_start_capture(const char* call_id, const char* res_id, int audio_format /*= 0*/, int volume/* = 180*/, int loudness /*= 0*/, const char* capture_device /*= nullptr*/,void* user_data);

/** @fn bool nim_audio_stop_capture()
  * NIM SDK 停止录制语音
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_stop_capture();

/** @fn bool nim_audio_cancel_audio(const char* file_path)
  * NIM SDK 取消录制并删除临时文件
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_cancel_audio(const char* file_path); //win32,ios,android

/** @fn bool nim_audio_reg_enum_capture_device_cb(nim_enum_capture_device_cb cb)
  * NIM SDK 注册枚举本地录音采集设备回调
  * @param[in] cb 回调函数 见nim_audio_def.h
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_reg_enum_capture_device_cb(nim_enum_capture_device_cb cb); //win32

/** @fn bool nim_audio_enum_capture_device()
  * pc有效
  * NIM SDK 枚举本地录音采集设备
  * @return bool true 调用成功，false 调用失败
  */
   NAUDIO_API bool nim_audio_enum_capture_device(); //win32

   //获取当前采集的时长
   NAUDIO_API int nim_audio_get_capture_time();

   //获取播放进度
   NAUDIO_API int nim_audio_get_play_current_position();
  
   //获取播放文件的时长
   NAUDIO_API bool  nim_audio_get_play_time();

   //设置扬声器播放,capture 为ture,表示音频采集状态下设置扬声器，capture为false,表示音频播放状态下设置扬声器
   NAUDIO_API void nim_audio_set_play_speaker(bool speaker, bool capture);
   
   //是否是扬声器
   NAUDIO_API bool nim_audio_get_play_speaker();


#ifdef __cplusplus
};
#endif //__cplusplus
#endif //_NIM_AUDIO_MODULE_SDK_H_
