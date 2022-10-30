package com.example.dice

import android.content.Context
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.*
import java.util.Random

class Score{
    var num : Array<Int> = Array(20,{i->0})
        set(value){
            field = value
        }
        get(){
            return field
        }
    var preNum : Int = 0
        set(value){
            field= value
        }
        get(){
            return field
        }
    var count : Int = 0
        set(value){
            field= value
        }
        get(){
            return field
        }
    fun record(value:Int){
        if(this.preNum == value){
            this.num[this.count] = value + 10
        }else{
            this.num[this.count] = value
        }
        this.preNum = value
        this.count++
        if(this.count>19){
            this.printNum()
        }
    }
    fun printNum(){
        for(i in 0..count-1){
            if(i == 10){
                println()
            }
            if(this.num[i] > 15){
                print("15(초과) ")
            }else{
                print("${this.num[i]} ")
            }
        }
        this.num = Array(20, {i->0})
        this.count = 0
        this.preNum = 0
    }
}
class Dice{
    var num : Int = 0
        get(){
            return field
        }
        set(value){
            field = value
        }
    fun play20(s: Score){
        for(i in 0..19){
            this.rollDice(s)
        }
    }
    fun rollDice(s: Score){
        var random = Random()
        this.num = random.nextInt(10)+1
        s.record(this.num)
    }
}
class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val btn = findViewById<Button>(R.id.button)
        val listView = findViewById<ListView>(R.id.listview)

        btn.setOnClickListener{
            var score = Score()
            var dice = Dice()
            dice.play20(score)
        }
        //        어답터 설정
        listView.adapter = MyCustomAdapter(this)
    }

    //    Adapter class
    private class MyCustomAdapter(context: Context) : BaseAdapter() {
        private val mContext: Context


        init {
            mContext = context
        }
        override fun getCount(): Int {
            return names.size
        }

        override fun getItemId(position: Int): Long {
            return position.toLong()
        }
        override fun getItem(position: Int): Any {
            val selectItem = names.get(position)
            return selectItem
        }
    }
}