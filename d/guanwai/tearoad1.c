
inherit ROOM;

void create()
{
        set("short", "茶马古道");
        set("long", @LONG
远在西汉时，张骞历尽艰辛，开辟出了这条西达西藏，北通巴蜀，东联滇越的
古道，到唐时，樊绰在其《蛮书》中就清楚提到了由滇入吐蕃的道路。随着茶的兴
起和传播，这条道路便成了名副其实的茶马古道。古道的石板上仍残留着有二寸多
深的马蹄印，道旁的嘛呢堆上刻画着各种神佛和宗教箴言。若有幸碰上七八十岁的
藏族老人访谈，他会喝着酥油茶，用苍凉的声音讲述茶叶入藏的故事。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"birdroad2",
  "east" : __DIR__"tearoad2",
]));
        set("outdoors", "guanwai");

	set("coor/x",100);
	set("coor/y",-90);
	set("coor/z",0);
	set("objects", ([
                __DIR__"obj/shiban" : 1,
        ]));
	setup();
}

void init()
{
        add_action("do_go","go");

}

int do_go(string arg )
{
	if ( arg == "east" || arg == "northwest") {
	        if(random(5)){
	                this_player()->move(this_object());
	                return 1;
	        } 
        } else 
        	return 0;  
        return 0;
}

