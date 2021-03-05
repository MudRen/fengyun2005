inherit ROOM;
void create()
{
        set("short", "地牢");
        set("long", @LONG
这里是济南百姓闻风丧胆的地牢，别说是普通强盗小贼，就算你有天大的
本领，到了这地牢，也只有等死的命。地牢积了齐胸高的水，冰冷刺骨，更加
上常年犯人的血水、排泄物已经恶臭不堪。牢中暗无天日，只有耳边一丝丝微
弱痛苦的呻吟。。。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "northup" : __DIR__"andao2",
]));
        set("objects", ([
        __DIR__"npc/laoqi" : 1,
                        ]) );

	set("coor/x",60);
	set("coor/y",0);
	set("coor/z",-20);
	set("jinan_prison",1);
	set("no_fly",1);
	setup();
        
}
