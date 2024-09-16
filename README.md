> [!CAUTION]
> This repository is not being actively maintained, however there is an active [AC fork here](https://github.com/azerothcore/mod-breaking-news-override).

# Breaking News Override
This module utilizes the Warden Payload Manager to enable the Breaking News frame on the left side of the character selection screen. You can feed it a html file defined in the config to use it.

# Setup
- Create a html file which contains the body for your breaking news frame.
- Set the path to the html file in the config.
- Enable the module and login to verify it works.

# Notes
There is a small amount of html tags that are actually compatible, follow this guide here: https://wowwiki-archive.fandom.com/wiki/UIOBJECT_SimpleHTML

You must escape the characters `[`, `]`, `'`, `\` in your title and html file because of the way the payload is sent.
Example:
`\'You think this hurts? Just wait.\'`

# Credits
Thanks to the AzerothCore community and Foe especially for getting this to work.
