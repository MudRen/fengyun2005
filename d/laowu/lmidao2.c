// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
string stone();


string poem1 = "浩浩愁茫茫劫短歌终明月缺郁郁佳城中有碧血碧亦有时尽血亦有时灭一缕香魂无断绝是耶非耶化为蝴蝶";
string final;


void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
秘道在这里突然变宽变大，形成了一个巨大的石室，室内长满了各种千奇百怪
的钟乳石，在光线的照耀下闪烁着迷人的色彩，如果没有光线你很难从这里绕出去。
石室一角有一个巨大的白石，象一张天然的书桌。
LONG
        );
        set("exits", ([ 
  			"west" : __DIR__"lmidao1",
  			"north" : __DIR__"lmidao3",
  			"northeast" : __DIR__"lmidao4",
		]));
		set("item_desc", ([
			"stone" : (: stone :),
			"白石" : (: stone :),
		]) );
		set("marks/finished", 0);
		set("coor/x",100);
		set("coor/y",30);
		set("coor/z",0);
	    setup();
}

void init(){
   add_action("do_write", "write");
}

string stone(){
	object me;
	me = this_player();
	if(query("marks/finished")){
		tell_object(me, "一块表面十分平滑的白石。\n");
	} else {
		tell_object(me, "一块表面十分平滑的白石，上面平铺了一张宣纸，上面写了些字：\n\n"); 
		tell_object(me,query("final"));
		tell_object(me, "其中似乎少了三个字，纸边摆着现成的笔墨。 \n");
	}
	return "";
}


int do_write(string arg){
   	  object  me, room;
   	  string msg, msg1, msg2;
   	  
	  me = this_player();
	  if(query("marks/finished")){
	      tell_object(me,"好好的一首词，还写些什么？\n");
	      return 1;
	  } 
   	  
   	  msg = query("num1")+ query("num2") + query("num3");
   	  msg1 = query("num1")+"　"+ query("num2")+"　"+ query("num3");
   	  msg2 = query("num1")+" "+ query("num2")+" "+query("num3");
   	  
   	   	 
      if(!arg || (arg != msg && arg != msg1 && arg!= msg2)) {
         tell_object(me,"你提笔欲写，却总觉得不甚贴切。\n");
         return 1;
      }
      
      tell_object(me, "你略一沉吟，提笔在空格上填了几个字，又把笔放了下去。\n");
      message("vision", me->name()+"略一沉吟，从白石上提笔写了几个字，又把笔放了回去。\n",environment(me), me);

      set("marks/finished",1);
      me->set_temp("marks/guest", 1);
      tell_object(me, "你只觉得后脑勺似乎被什么东西叮了一下。\n");
      me->unconcious();
      message("vision", "你只觉得眼前一花，似有一个人影掠过，"+ me->name() +"已经失去了踪影。\n", environment(me),me);
      room = find_object(AREA_SHENSHUI"woshi2");
      if(!objectp(room)) room=load_object(AREA_SHENSHUI"woshi2");
      me->move(room);
//	  me->set("marks/enter_ss/白石",1);  	  
   	  return 1;
}



void reorder(){
	
	string final, poem;
	int num1, num2, num3,i;
	
	num1 = random(12)*2 + 2;	
	num2 = random(18)*2 + 24;
	num3 = random(14)*2 + 60;
	
	poem = poem1[0..num1-1]+ "□" + poem1[num1+2..num2-1] + "□" 
			+ poem1[num2+2..num3-1] + "□" + poem1[num3+2..89];
	
	final = "\n		"+ poem[0..5]+"，"+poem[6..11]+"，\n"
			+"		"+ poem[12..17]+"，"+poem[18..23]+"。\n"
			+"		"+ poem[24..31]+"，"+poem[32..39]+"。\n"
			+"		"+ poem[40..49]+"，"+poem[50..59]+"，\n"
			+"		"+ poem[60..73]+"！\n"
			+"		"+ poem[74..81]+"，"+poem[82..89]+"。\n\n";

	
	set("num1", poem1[num1..num1+1]);
	set("num2", poem1[num2..num2+1]);
	set("num3", poem1[num3..num3+1]);
	set("final",final);	
	return;
}

void reset(){
	::reset();
	reorder();
	delete("marks/finished");
}
