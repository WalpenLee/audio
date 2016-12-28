package com.example.hzliwangpeng.nim_audio_test_aos;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import com.netease.unitywrapper.player.*;
import com.netease.unitywrapper.recorder.*;

public class MainActivity extends AppCompatActivity {

    private Button btn_Init_=null;
    private Button btn_UnInit_=null;
    private Button btn_StartCaptrue_=null;
    private Button btn_StopCapture_=null;
    private Button btn_CancelCapture_=null;
    private Button btn_StartPlay_=null;
    private Button btn_StopPlay_=null;
    private Button btn_Speaker_=null;
    private TextView tv_info_=null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn_Init_=(Button)findViewById(R.id.init);
        btn_UnInit_=(Button)findViewById(R.id.uninit);
        btn_StartCaptrue_=(Button)findViewById(R.id.startcapture);
        btn_StopCapture_=(Button)findViewById(R.id.stopcapture);
        btn_CancelCapture_=(Button)findViewById(R.id.cancelcapture);
        btn_StartPlay_=(Button)findViewById(R.id.startplay);
        btn_StopPlay_=(Button)findViewById(R.id.stopplay);
        btn_Speaker_=(Button)findViewById(R.id.speaker);
        tv_info_=(TextView) findViewById(R.id.textView2);
        tv_info_.setMovementMethod(ScrollingMovementMethod.getInstance());
       btn_Init_.setOnClickListener(new View.OnClickListener() {
           @Override
           public void onClick(View v) {
               tv_info_.setText("Init\n"+tv_info_.getText());

           }
       });

        btn_UnInit_.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_info_.setText("UnInit\n"+tv_info_.getText());
            }
        });

       btn_StartCaptrue_.setOnClickListener(new View.OnClickListener() {
           @Override
           public void onClick(View v) {
               tv_info_.setText("StartCapture\n"+tv_info_.getText());
           }
       });

        btn_StopCapture_.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_info_.setText("StopCapture\n"+tv_info_.getText());
            }
        });

        btn_CancelCapture_.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_info_.setText("CancelCapture\n"+tv_info_.getText());
            }
        });

        btn_StartPlay_.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_info_.setText("StartPlay\n"+tv_info_.getText());
            }
        });

        btn_StopPlay_.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_info_.setText("StopPlay\n"+tv_info_.getText());
            }
        });

        btn_Speaker_.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_info_.setText("Speaker\n"+tv_info_.getText());
            }
        });

    // Example of a call to a native method
    TextView tv = (TextView) findViewById(R.id.sample_text);
    tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native boolean nim_audio_init_module(String user_data_parent_path);
    public native boolean nim_audio_uninit_module();
    public native boolean nim_audio_play_audio(String file_path,int audio_format);
    public native boolean nim_audio_stop_play_audio();
    //public native boolean nim_audio_reg_start_play_cb();
    //public native boolean nim_audio_reg_stop_play_cb();
    //public native boolean nim_audio_reg_play_end_cb();
    //public native boolean nim_audio_reg_start_capture_cb();
    //public native boolean nim_audio_reg_stop_capture_cb();
    //public native  boolean nim_audio_reg_cancel_audio_cb();
    //public native boolean nim_audio_reg_audio_error_cb();
    //public native boolean nim_audio_reg_get_play_current_position_cb();
    //public native boolean nim_audio_reg_get_capture_time_cb();
    public native  boolean nim_audio_start_capture(int audio_format);
    public native  boolean nim_audio_stop_capture();
    public native boolean nim_audio_cancel_audio(String file_path);
    //public native boolean nim_audio_get_capture_time();
    //public native boolean nim_audio_get_play_current_position();
   // public native boolean nim_audio_get_play_time();
    //public native boolean nim_audio_set_play_speaker(boolean speaker,boolean capture);
    //public native boolean nim_audio_get_play_speaker();

    //public interface  AudioCallBack extends
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
