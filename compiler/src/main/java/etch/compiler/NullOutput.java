package etch.compiler;

import java.io.File;
import java.io.IOException;
import java.io.OutputStream;

/**
 * Implementation of Output which does nothing.
 */
public class NullOutput implements Output
{
	public OutputStream newOutputStream( String fn )
	{
		return new OutputStream()
		{
			@Override
			public void write( int b ) throws IOException
			{
				// ignore, we don't want the output.
			}
		};
	}

	public Output newPackage( String pn )
	{
		// ignore, we don't care what the package is.
		return this;
	}
	
	public void report( String what )
	{
		// ignore, nothing to report.
	}

	public void saveFiles( File outputDir, boolean noQualOutputDir,
		boolean noFlattenPackages, boolean force )
	{
		// ignore, nothing to save.
	}
}