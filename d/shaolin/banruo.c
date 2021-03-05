// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "般若堂");
        set("long", @LONG
为念跋陀传“摩珂般若法”而建，后成为高僧居所，并裁决事宜，与达摩院，
罗汉堂并列，但凡少林后辈弟子武功，佛法能胜过达摩院长老，便可以在这里居住，
屋中并不豪华，但是整洁清雅，有小沙弥专事整理。
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"xueshen",
  "southwest" : __DIR__"yangxing",
  "north": __DIR__"muren",
  "east": __DIR__"lao",
  "west" : __DIR__"meiyuan",
]));
        set("objects", ([
                __DIR__"npc/monk11" : 2,
       ]) );
	set("coor/x",0);
	set("coor/y",120);
	set("coor/z",20);
	setup();
}

int valid_leave(object me, string dir)
{

	if (dir == "north")
		return notify_fail("少林木人巷装修，不日内将重新开放。\n");
	
	if (dir=="north" && me->query("family/master_id") =="damo")
        {
            tell_object(me,"你隐隐听到达摩祖师的声音：争强斗胜,岂是佛门弟子所为,你还不曾悟么?\n");
            return notify_fail("");
        }

	if(dir == "north" && me->query("class") == "shaolin" 
                      && me->query("family/generation") > 10)
    	{
        /* shaolin students */

        
        if (me->query_skill("zen", 1) < 175 || me->query_skill("chanting", 1) < 200)
        {
            message_vision("一股大力将$N推了回来，
一个苍老的声音说道：凭你的禅道修为和定力，根本不能出少林。\n",me);
            return notify_fail("");
        }

        if (me->query("marks/muren_time") && (me->query("marks/muren_time") + 48 * 3600 > me->query("mud_age"))) {
            message_vision("一股大力将$N推了回来，
一个苍老的声音说道：你不久前刚败在木人巷，还是去练几年武艺再来吧。\n",me);
            return notify_fail("");
        }

        me->set("marks/muren_time", me->query("mud_age"));

    }
    return 1;
}

