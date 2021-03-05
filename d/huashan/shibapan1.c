#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "十八盘");
        set("long", @LONG
此处山势陡峭，盘山土路陡峭艰辛，路随山势曲折盘环，十有八折盘山而上，
路旁荆棘丛生，你不时的被荆棘牵挂衣冠。
LONG
        );
    set("exits", ([ 
  		"southwest" : __DIR__"shibapan2",
  		"northwest" : __DIR__"shibapan",
	]));
	set("objects", ([
		__DIR__"obj/jingji" : 1,
		__DIR__"npc/explorer2" : 1,
		
	]) );

   	set("bird_came", 0);
    	set("outdoors", "huashan");

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

void init(){
    int i;        
    i = NATURE_D->set_season();
	if(i == 4){
		return;
	}
   	if(NATURE_D->is_day_time() && NATURE_D->get_weather() == "晴" 
    		&& !query("bird_came")) {
		set("bird_came", 1);
        call_out("bird_come", random(30), this_player());
    }    
}

int bird_come(object me){
    object bird;
    
    if (!me)	return 0;
    if(environment(me) != this_object()) {
    	return 0;
    }

    bird = new(__DIR__"npc/ybird");
    if(objectp(bird) && !present("yellow bird", this_object()) ){
        bird->move(this_object());
        message_vision(YEL"\n只见一道黄色的影子从你眼前滑过，一只小黄雀坠落在路旁的荆棘丛中。\n"NOR,
                bird);
        message_vision("一道灰色的影子从南边掠过，在你的头顶徘徊久久不去。\n", bird);
    } 

}

void reset(){
	::reset();
	if (!random(8))
		delete("bird_came");
}
