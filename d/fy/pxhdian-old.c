inherit ROOM;
void create()
{
        set("short", "飘香花店");
        set("long", @LONG
经过了这么多年，这里似乎一点都没有改变。店面也没有什么改变，人来人往地
不断。未入此处，清新的花香已沁人心裨。店中各种名花，玲琅满目，不乏珍奇异种。
来客不分高低贵贱，这里的主人总是笑脸相迎。许多城中的年青人都喜欢在这儿逗留，
盼有一天桃花运会降临在他身上。据这里的老板说，在飘香花店结成的良缘已不可胜
数。店门口红纸贴了张告示（ｓｉｇｎ）。
LONG
        );
        set("exits", ([
		"west" : __DIR__"nwind2",
        ]));
        set("objects", ([
                __DIR__"npc/flowerseller": 1,
        ]) );
        set("item_desc", ([
                "sign": @TEXT
             关关雎鸠，在河之洲。
             窈窕淑女，君子好逑。
本花店蒙各方惠顾，生意兴隆，现缺若干人手送花各地：

delivery     按顾主所托，送花给指定贵客，凡接手者
             须预付定金一银。
deposit      完成该次送花后，可向店主花满城询问取
             回定金（ask huaman about deposit）
cancel       若是因各种原因无法完成接手之责，可取
             消这次任务（cancel delivery)。
TEXT
        ]) );
        set("no_fight",1);
        set("no_magic",1);
	set("coor/x",3);
	set("coor/y",60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}
