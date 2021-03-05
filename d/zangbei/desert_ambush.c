inherit ROOM;

void create()
{
        set("short", "沙丘");
        set("long", @LONG
沙丘并不大，转过沙丘，就瞧见一个人，这个简直已不大像是人，而像是一只
被架在火上，快被烤焦了的羊，他赤裸裸地被人钉在地上，手腕。足踝，和面额上，
都绑着牛皮，牛皮本来是湿的，被太阳晒乾後，就越来越紧，直嵌入肉里。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"yangguan1c",
		"north" : __DIR__"mirage",
		]));
	set("objects", ([
		__DIR__"npc/assassin" : 1,
		
	]));
	set("item_desc",([
	
	]));
	set("outdoors", "zangbei");
    set("coor/x",-90);
	set("coor/y",290);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}


void reset(){
	object man;
	::reset();
	set("long", @LONG
沙丘并不大，转过沙丘，就瞧见一个人，这个简直已不大像是人，而像是一只
被架在火上，快被烤焦了的羊，他赤裸裸地被人钉在地上，手腕。足踝，和面额上，
都绑着牛皮，牛皮本来是湿的，被太阳晒乾後，就越来越紧，直嵌入肉里。
LONG
        );
        if (man = present("trader",this_object()))
        	if (!man->is_fighting()) {
        		man->set("name","客商");
        		man->set("chat_chance",1);
        	}
}
