inherit __DIR__"no_killing_place";
void create()
{
    
	set("short", "小桥");
    
	set("long", @LONG
汉白玉雕成的小桥通体洁白。水流轻快的从桥下流过，河水清澈见底，站在桥
上你可以清楚地看到鹅卵石铺成的河床，不时游过的鱼儿在鹅卵石上投下了淡淡的
阴影。东岸连绵不断的山峦环绕着一块绿色的盆地，盆地中依山傍河坐落着几个精
致的小宅院，四周花草扶疏。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"riverbank",    
		"east" : __DIR__"riverbanke",
	]));
    
	set("no_magic", 1);
	set("outdoors","taoyuan");
	set("coor/x",60);
	set("coor/y",0);
	set("coor/z",0);
    
	setup();
    
	
}
