inherit ITEM;

void create()
{
        set_name("《踏月留香图》", ({ "painting"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "挂");
                set("long", "一挂描绘粗劣的《踏月留香图》，画的是踏月色而行的翩翩公子楚香帅。\n");
                set("value", 50000);
        }
        ::init_item();
}


void init()
{
        if(this_player()==environment())
                add_action("do_look","look");
}

int do_look(string arg)
{
    object me,ob;
    me = this_player();
        if (!arg)
                return 0;
        ob = present(arg,me);
        if (!ob)
                return 0;
        if (ob != this_object())
                return 0;

        tell_object(me,"一挂描绘粗劣的《踏月留香图》，画的是踏月色而行的翩翩公子楚香帅。\n在风云里很受欢迎，因此价格也节节拔高。\n");

        if (me->query("gender") == "男性")
        {
                message("vision", me->name() + "展开一卷" + ob->name() + "，不屑的啐了一声，自言自语道：\n这小白脸算什么？英俊潇洒玉树临风的本公子可比他帅多了。\n", environment(me), me);
                tell_object(me,"你展开画看了一眼，不屑的啐了一声，想道：这小白脸算什么？英俊潇洒玉树临风的本公子可比他帅多了。\n");
                return 1;
        }
        
   switch( random(3) ) {
                        case 0:
        message("vision", me->name() + "看了眼" + ob->name()
                        + "，又收起来紧紧的拢在怀里。\n", environment(me), me);
                                        break;
                        case 1:
        message("vision", me->name() + "又偷偷瞄了手里的" + ob->name()
                        + "一眼，眼光痴傻迷离。\n", environment(me), me);
                                        break;
                        case 2:
        message("vision", me->name() + "展开" + ob->name()
                        + "轻抚，脸上泛起一抹红晕。\n", environment(me), me);
                                        break;
        }
        message("vision", me->name() + "呆呆的对画傻笑，神游方外。\n", environment(me), me);
        write("\n你感到心头有只小鹿急撞，＂砰＂，＂砰＂，＂砰＂．．．\n");
        me->unconcious();
        return 1;
}

