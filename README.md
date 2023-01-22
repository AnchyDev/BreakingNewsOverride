# Breaking News Override
This module allows you to override and show the breaking news frame on the left side of the character selection screen.

![Image](https://cdn.discordapp.com/attachments/814444289181351968/1065844717994127370/Screenshot_2023-01-20_150406.png)

# Setup
- Create a html file which contains the body for your breaking news frame.
- Set the path to the html file in the config.
- Enable the module and login to verify it works.

# Notes
There is a small amount of html tags that are actually compatible, follow this guide here: https://wowwiki-archive.fandom.com/wiki/UIOBJECT_SimpleHTML

You must escape the characters `[`, `]`, `'` in your html file because of the way the payload is sent.
Example:
`\'You think this hurts? Just wait.\'`

# Credits

Thanks to the AzerothCore community and Foe especially for getting this to work.